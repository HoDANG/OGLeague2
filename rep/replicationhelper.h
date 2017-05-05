#ifndef REPLICATIONHELPER_H
#define REPLICATIONHELPER_H

#include "replicationmanager.h"
#include "../obj/gameobjectsall.h"

struct ReplicationHelper
{
    static FillBuildingLocalRepData(Game::AttackableUnit *building,
                                    CReplInfo32 *ri, ReplicationManager* manager, void* base);
};

#endif // REPLICATIONHELPER_H
