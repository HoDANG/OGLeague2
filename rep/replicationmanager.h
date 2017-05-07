#ifndef REPLICATIONMANAGER_H
#define REPLICATIONMANAGER_H

#include <vector>
#include <string.h>
#include <bitset>

enum ReplicationType
{
    CLIENT_ONLY_REP_DATA = 0x1,
    LOCAL_REP_DATA1 = 0x2,
    LOCAL_REP_DATA2 = 0x4,
    MAP_REPDATA = 0x8,
    ONVISIBLE_REP_DATA = 0x10,
};


struct CReplInfo32
{
    int numVars = 0;
    std::string varNames[32];
    int addVar(std::string name)
    {
        if(numVars > 0)
            for(int i = 0;i<numVars;i++)
                if(_stricmp(varNames[i].c_str(),name.c_str()))
                    return i;
        varNames[numVars] = name;
        return numVars++;
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
};

struct ReplicationManager
{
    CReplData32 mClientOnlyRepData1;
    CReplData32 mLocalRepData1;
    CReplData32 mLocalRepData2;
    CReplData32 mMapRepData;
    CReplData32 mOnVisibleRepData;
    unsigned int mSyncIDClientOnly = 0;
    unsigned int mSyncIDRepData1 = 0;
    unsigned int mSyncIDRepData2 = 0;
    unsigned int mSyncIDMapRepData = 0;
    unsigned int mSyncIDOnVisibleRepData = 0;
    void Init(CReplInfo32 *npc_ClientOnly, CReplInfo32 *npc_LocalRepData1,
               CReplInfo32 *npc_LocalRepData2, CReplInfo32 *npc_MapRepData, CReplInfo32 *npc_OnVisibleRepData);
    void MarkChanged(ReplicationType type, int index, uint32_t value);
};

template<typename T>
struct Replicate
{
    T mValue;
    int mIndex;
    ReplicationType mType;
    ReplicationManager *mReplicator = nullptr;
    void SetReplicator(std::string name, CReplInfo32 *crep, ReplicationType type,
                        ReplicationManager *replicator)
    {
        this->mIndex = crep->addVar(name);
        this->mType = type;
        this->mReplicator = replicator;
        Set(mValue);
    }
    void Set(T newValue)
    {
        mValue = newValue;
        if(mReplicator != nullptr)
            mReplicator->MarkChanged(mType, mIndex, *((uint32_t*)&mValue));
    }
};
#endif // REPLICATIONMANAGER_H
