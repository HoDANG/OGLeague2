#include "replicationmanager.h"


void ReplicateI::Set(std::string newValue)
{

}

std::string ReplicateI::Value()
{
    return "";
}

ReplicationType ReplicateI::Type()
{
    return CLIENT_ONLY_REP_DATA;
}

uint32_t ReplicateI::Index()
{
    return 0;
}

uint32_t ReplicateI::Value32()
{
    return 255;
}

int CReplInfo32::addVar(std::string name, void *offset)
{
    if(numVars > 0)
        for(int i = 0;i<numVars;i++)
            if(StringUtils::stringicmp(varNames[i], name) == 0)
                return i;
    varNames[numVars] = name;
    varOffsets[numVars] = offset;
    return numVars++;
}

void *CReplInfo32::find(std::string name)
{
    if(numVars > 0)
        for(int i = 0;i<numVars;i++)
            if(StringUtils::stringicmp(varNames[i], name) == 0)
                return varOffsets[i];
    return nullptr;
}

void CReplData32::Init(CReplInfo32 *ri)
{
    info = ri;
    valuesThatHaveChanged = 0;
    firstTime = true;
}

void *CReplData32::find(std::string name)
{
    if(info == nullptr)
        return nullptr;
    return info->find(name);
}

bool CReplData32::Dump(std::vector<uint32_t> &data)
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

void ReplicationManager::Init(CReplInfo32 *npc_ClientOnly, CReplInfo32 *npc_LocalRepData1, CReplInfo32 *npc_LocalRepData2, CReplInfo32 *npc_MapRepData, CReplInfo32 *npc_OnVisibleRepData, void *base)
{
    mClientOnlyRepData1.Init(npc_ClientOnly);
    mLocalRepData1.Init(npc_LocalRepData1);
    mLocalRepData2.Init(npc_LocalRepData2);
    mMapRepData.Init(npc_MapRepData);
    mOnVisibleRepData.Init(npc_OnVisibleRepData);
    mBase = base;
}

void ReplicationManager::MarkChanged(ReplicationType type, int index, uint32_t value)
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

uint8_t ReplicationManager::DumpReplication(std::vector<uint32_t> &data)
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

ReplicateI *ReplicationManager::find(std::string name)
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
