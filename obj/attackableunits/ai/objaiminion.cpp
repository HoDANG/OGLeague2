#include "objaiminion.h"
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


ObjAiMinion::ObjAiMinion(World *world)
    : ObjAiBase(world)
{
}

void ObjAiMinion::SetupReplicationInfo()
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

    mHealth.mCurrent.mIndex = npc_LocalRepData1.addVar(this, &mHealth.mCurrent, "mHP");
    mHealth.mCurrent.mType = LOCAL_REP_DATA1;
    mHealth.mCurrent.mReplicator = &mReplicationManager;
    mPAR.mCurrent.mIndex = npc_LocalRepData1.addVar(this, &mPAR.mCurrent, "mMP");
    mPAR.mCurrent.mReplicator = &mReplicationManager;
    mPAR.mCurrent.mType = LOCAL_REP_DATA1;
    mHealth.mMax.mIndex = npc_LocalRepData1.addVar(this, &mHealth.mMax, "mMaxHP");
    mHealth.mMax.mType = LOCAL_REP_DATA1;
    mHealth.mMax.mReplicator = &mReplicationManager;
    mPAR.mMax.mIndex = npc_LocalRepData1.addVar(this, &mPAR.mMax, "mMaxMP");
    mPAR.mMax.mReplicator = &mReplicationManager;
    mPAR.mMax.mType = LOCAL_REP_DATA1;
    ReplicationHelper::FillLocalRepData(this, &charState, &npc_LocalRepData1, &mReplicationManager, this);
    ReplicationHelper::FillBasicLocalRepData(&charInterRep, &npc_LocalRepData1, &mReplicationManager, this);
    ReplicationHelper::FillBasicMapRepData(&charInterRep, &npc_MapRepData, &mReplicationManager, this);
    mReplicationManager.Init(this,
                             &npc_ClientSpecific,
                             &npc_LocalRepData1,
                             &npc_LocalRepData2,
                             &npc_MapRepData,
                             &npc_OnVisibleRepData);
}
