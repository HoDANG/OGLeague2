#include "objaihero.h"
#include "../../properties/replicationhelper.hpp"

ObjAiHero::ObjAiHero(World *world)
    : ObjAiBase(world)
{
    mReplicationManager.mBase = this;
    SetupReplicationInfo();
}

void ObjAiHero::SetupReplicationInfo()
{
    static uint32_t REP_FLAGS = 0;
    static CReplInfo32 npc_ClientSpecific;
    static CReplInfo32 npc_LocalRepData1;
    static CReplInfo32 npc_LocalRepData2;
    static CReplInfo32 npc_MapRepData;
    static CReplInfo32 npc_OnVisibleRepData;
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
    mExp.mExp.SetReplicator("mExp", &npc_ClientSpecific, CLIENT_ONLY_REP_DATA, &mReplicationManager);
    mGold.mValue.SetReplicator("mGold", &npc_ClientSpecific, CLIENT_ONLY_REP_DATA, &mReplicationManager);
    mCanCastBits1.SetReplicator("mCanCastBits1", &npc_ClientSpecific, CLIENT_ONLY_REP_DATA, &mReplicationManager);
    mCanCastBits2.SetReplicator("mCanCastBits2", &npc_ClientSpecific, CLIENT_ONLY_REP_DATA, &mReplicationManager);

    //Mana costs...


    mHealth.mCurrent.SetReplicator("mHP", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);
    mPAR.mCurrent.SetReplicator("mMP", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);
    mHealth.mMax.SetReplicator("mMaxHP", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);
    mPAR.mMax.SetReplicator("mMaxMP", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);

    ReplicationHelper::FillLocalRepData(this, &charState, &npc_LocalRepData1, &mReplicationManager);
    mIsPhysicalImmune.SetReplicator("IsPhysicalImmune", &npc_LocalRepData2, LOCAL_REP_DATA2, &mReplicationManager);
    mIsMagicImmune.SetReplicator("IsMagicImmune", &npc_LocalRepData2, LOCAL_REP_DATA2, &mReplicationManager);
    ReplicationHelper::FillHeroLocalRepData(&charInterRep, &npc_LocalRepData1, &mReplicationManager);
    ReplicationHelper::FillHeroMapRepData(&charInterRep, &npc_MapRepData, &mReplicationManager);

    mExp.mLevel.SetReplicator("mLevelRef", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);
    mDebugDrawRadius.SetReplicator("mDebugDrawRadius", &npc_MapRepData, MAP_REPDATA, &mReplicationManager);
    mReplicationManager.Init(&npc_ClientSpecific,
                             &npc_LocalRepData1,
                             &npc_LocalRepData2,
                             &npc_MapRepData,
                             &npc_OnVisibleRepData,
                             this);
}
