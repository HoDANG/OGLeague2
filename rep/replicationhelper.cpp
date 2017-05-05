#include "replicationhelper.h"

using namespace Game;

ReplicationHelper::FillBuildingLocalRepData(AttackableUnit *building, CReplInfo32 *ri, ReplicationManager* manager,
                                            void* base)
{
    building->mHealth.mCurrent.SetReplicator(base, "mHP", ri, LOCAL_REP_DATA1, manager);
    building->mIsInvulnerable.SetReplicator(base, "IsInvulnerable", ri, LOCAL_REP_DATA1, manager);
    building->mIsTargetable.SetReplicator(base, "IsTargetable", ri, LOCAL_REP_DATA1, manager);
    building->mIsTargetableToTeam.SetReplicator(base, "IsTargetableToTeam", ri, LOCAL_REP_DATA1, manager);
}
