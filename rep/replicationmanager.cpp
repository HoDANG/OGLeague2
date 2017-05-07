#include "replicationmanager.h"


void ReplicationManager::Init(CReplInfo32 *npc_ClientOnly,
                              CReplInfo32 *npc_LocalRepData1, CReplInfo32 *npc_LocalRepData2,
                              CReplInfo32 *npc_MapRepData, CReplInfo32 *npc_OnVisibleRepData)
{
    mClientOnlyRepData1.Init(npc_ClientOnly);
    mLocalRepData1.Init(npc_LocalRepData1);
    mLocalRepData2.Init(npc_LocalRepData2);
    mMapRepData.Init(npc_MapRepData);
    mOnVisibleRepData.Init(npc_OnVisibleRepData);
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
    if(rd->info == nullptr)
        return;
    rd->valuesThatHaveChanged |= (1 << index);
    rd->mValueCopy[index] = value;
}


