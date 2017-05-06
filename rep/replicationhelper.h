#ifndef REPLICATIONHELPER_H
#define REPLICATIONHELPER_H

#include "replicationmanager.h"
#include "../obj/gameobjectsall.h"
#include "characterintermediaterep.h"
#include "characterstate.h"

struct ReplicationHelper
{
    static FillBuildingLocalRepData(Game::AttackableUnit *building,
                                    CReplInfo32 *ri, ReplicationManager* manager, void* base);
    static FillBasicLocalRepDataTower(CharacterIntermediateRep *building,
                                     CReplInfo32 *ri, ReplicationManager* manager, void* base);
    static FillLocalRepData(Game::AttackableUnit *unit, CharacterState *state,
                            CReplInfo32 *ri, ReplicationManager* manager, void* base);
    static FillBasicMapRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                               ReplicationManager* manager, void* base);
    static FillBasicLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                                 ReplicationManager* manager, void* base);

};

#endif // REPLICATIONHELPER_H
