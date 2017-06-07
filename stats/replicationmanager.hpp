#ifndef REPLICATIONMANAGER_H
#define REPLICATIONMANAGER_H

#include <vector>
#include <string.h>
#include <bitset>
#include <sstream>
#include "stringutils.hpp"

enum ReplicationType
{
    CLIENT_ONLY_REP_DATA = 0x1,
    LOCAL_REP_DATA1 = 0x2,
    LOCAL_REP_DATA2 = 0x4,
    MAP_REPDATA = 0x8,
    ONVISIBLE_REP_DATA = 0x10,
};

struct ReplicateI
{
    virtual void Set(std::string newValue)
    {

    }
    virtual std::string Value()
    {
        return "";
    }
    virtual ReplicationType Type()
    {
        return CLIENT_ONLY_REP_DATA;
    }
    virtual uint32_t Index()
    {
        return 0;
    }
    virtual uint32_t Value32()
    {
        return 255;
    }
};

struct CReplInfo32
{
    int numVars = 0;
    std::string varNames[32];
    void* varOffsets[32];
    int addVar(std::string name, void *offset)
    {
        if(numVars > 0)
            for(int i = 0;i<numVars;i++)
                if(StringUtils::stringicmp(varNames[i], name) == 0)
                    return i;
        varNames[numVars] = name;
        varOffsets[numVars] = offset;
        return numVars++;
    }
    void* find(std::string name)
    {
        if(numVars > 0)
            for(int i = 0;i<numVars;i++)
                if(StringUtils::stringicmp(varNames[i], name) == 0)
                    return varOffsets[i];
        return nullptr;
    }
};

struct CReplData32
{
    CReplInfo32 *info = nullptr;
    uint32_t valuesThatHaveChanged = 0;
    uint32_t mValueCopy[32];
    bool firstTime = false;
    void Init(CReplInfo32 *ri)
    {
        info = ri;
        valuesThatHaveChanged = 0;
        firstTime = true;
    }

    void* find(std::string name)
    {
        if(info == nullptr)
            return nullptr;
        return info->find(name);
    }

    bool Dump(std::vector<uint32_t> &data)
    {
        if(valuesThatHaveChanged == 0)
            return false;
        data.push_back(valuesThatHaveChanged);
        for(int i = 0; i<info->numVars; i++)
            if(valuesThatHaveChanged & ((uint32_t)1<<i))
                data.push_back(mValueCopy[i]);
        valuesThatHaveChanged = 0;
        return true;
    }
};

struct ReplicationManager
{
    CReplData32 mClientOnlyRepData1;
    CReplData32 mLocalRepData1;
    CReplData32 mLocalRepData2;
    CReplData32 mMapRepData;
    CReplData32 mOnVisibleRepData;
    uint32_t mModified = 0;
    void *mBase = nullptr;
    void Init(CReplInfo32 *npc_ClientOnly, CReplInfo32 *npc_LocalRepData1, CReplInfo32 *npc_LocalRepData2,
              CReplInfo32 *npc_MapRepData, CReplInfo32 *npc_OnVisibleRepData, void *base = nullptr)
    {
        mClientOnlyRepData1.Init(npc_ClientOnly);
        mLocalRepData1.Init(npc_LocalRepData1);
        mLocalRepData2.Init(npc_LocalRepData2);
        mMapRepData.Init(npc_MapRepData);
        mOnVisibleRepData.Init(npc_OnVisibleRepData);
        mBase = base;
    }
    void MarkChanged(ReplicationType type, int index, uint32_t value)
    {
        CReplData32 *rd = nullptr;
        switch(type)
        {
        case CLIENT_ONLY_REP_DATA:
            rd = &mClientOnlyRepData1;
            break;
        case LOCAL_REP_DATA1:
            rd = &mLocalRepData1;
            break;
        case LOCAL_REP_DATA2:
            rd = &mLocalRepData2;
            break;
        case MAP_REPDATA:
            rd = &mMapRepData;
            break;
        case ONVISIBLE_REP_DATA:
            rd = &mOnVisibleRepData;
            break;
        }
        if(rd == nullptr)
            return;
        mModified |= type;
        rd->valuesThatHaveChanged |= (1 << index);
        rd->mValueCopy[index] = value;
    }
    uint8_t DumpReplication(std::vector<uint32_t> &data)
    {
        if(mModified == 0)
            return 0;
        mClientOnlyRepData1.Dump(data);
        mLocalRepData1.Dump(data);
        mLocalRepData2.Dump(data);
        mMapRepData.Dump(data);
        mOnVisibleRepData.Dump(data);
        mModified = 0;
        return mModified;
    }
    ReplicateI* find(std::string name)
    {
        if(!mBase)
            return nullptr;
        void* offset = mClientOnlyRepData1.find(name);
        if(!offset)
            offset = mLocalRepData1.find(name);
        if(!offset)
            offset = mLocalRepData2.find(name);
        if(!offset)
            offset = mMapRepData.find(name);
        if(!offset)
            offset = mOnVisibleRepData.find(name);
        if(!offset)
            return nullptr;
        return (ReplicateI*)((void*)(uint64_t(mBase)+uint64_t(offset)));
    }
};

template<typename T>
struct Replicate : ReplicateI
{
    T mValue;
    int mIndex = 0;
    ReplicationType mType;
    ReplicationManager *mReplicator = nullptr;
    void SetReplicator(std::string name, CReplInfo32 *crep, ReplicationType type,
                        ReplicationManager *replicator)
    {
        void *offset = nullptr;
        if(replicator->mBase != nullptr)
            offset = (void*) (uint64_t(this) - uint64_t(replicator->mBase));
        mIndex = crep->addVar(name, offset);
        mType = type;
        mReplicator = replicator;
        Set(mValue);
    }

    void Set(T newValue)
    {
        mValue = newValue;
        if(mReplicator != nullptr)
            mReplicator->MarkChanged(mType, mIndex, *((uint32_t*)&mValue));
    }

    void Set(std::string newValue)
    {
        T value;
        std::stringstream ss;
        ss<<newValue;
        ss>>value;
        Set(value);
    }
    std::string Value()
    {
        std::stringstream ss;
        ss<<mValue;
        return ss.str();
    }

    ReplicationType Type()
    {
        return mType;
    }

    uint32_t Index()
    {
        return mIndex;
    }
    uint32_t Value32()
    {
        return *((uint32_t*)&mValue);
    }
};
#endif // REPLICATIONMANAGER_H
