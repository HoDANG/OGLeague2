#include "objaiturret.h"
#include "../../../rep/replicationhelper.h"

using namespace Game;

namespace
{
    uint32_t REP_FLAGS = 0;
    CReplInfo32 npc_ClientSpecific;
    CReplInfo32 npc_LocalRepData1;
    CReplInfo32 npc_LocalRepData2;
    CReplInfo32 npc_MapRepData;
    CReplInfo32 npc_OnVisibleRepData;
}

ObjAiTurret::ObjAiTurret(World *world)
    : ObjAiBase(world)
{

    mReplicationManager.mBase = this;
    SetupReplicationInfo();
}

void ObjAiTurret::SetupReplicationInfo()
{
    if ( !(REP_FLAGS & CLIENT_ONLY_REP_DATA) )
    {
        REP_FLAGS = REP_FLAGS | CLIENT_ONLY_REP_DATA;
        npc_ClientSpecific.numVars = 0;
    }
    if ( !(REP_FLAGS & LOCAL_REP_DATA1) )
    {
        REP_FLAGS |= LOCAL_REP_DATA1;
        npc_LocalRepData1.numVars = 0;
    }
    if ( !(REP_FLAGS & LOCAL_REP_DATA2) )
    {
        REP_FLAGS |= LOCAL_REP_DATA2;
        npc_LocalRepData2.numVars = 0;
    }
    if ( !(REP_FLAGS & MAP_REPDATA) )
    {
        REP_FLAGS |= MAP_REPDATA;
        npc_MapRepData.numVars = 0;
    }
    if ( !(REP_FLAGS & ONVISIBLE_REP_DATA) )
    {
        REP_FLAGS = REP_FLAGS | ONVISIBLE_REP_DATA;
        npc_OnVisibleRepData.numVars = 0;
    }
    ReplicationHelper::FillBasicLocalRepDataTower(&charInterRep,&npc_LocalRepData1, &mReplicationManager);
    mHealth.mCurrent.SetReplicator("mHP", &npc_LocalRepData1, LOCAL_REP_DATA1, &mReplicationManager);
    mHealth.mMax.SetReplicator("mMaxHP", &npc_LocalRepData1, LOCAL_REP_DATA1, &mReplicationManager);
    ReplicationHelper::FillLocalRepData(this, &charState, &npc_LocalRepData1, &mReplicationManager);
    ReplicationHelper::FillBasicMapRepData(&charInterRep, &npc_MapRepData, &mReplicationManager);
    mReplicationManager.Init(&npc_ClientSpecific,
                             &npc_LocalRepData1,
                             &npc_LocalRepData2,
                             &npc_MapRepData,
                             &npc_OnVisibleRepData,
                             this);
}
