#ifndef REPLICATIONHELPER_H
#define REPLICATIONHELPER_H

#include "replicationmanager.h"
#include "../obj/gameobjectsall.h"
#include "characterintermediaterep.h"
#include "characterstate.h"

struct ReplicationHelper
{
    static void FillBuildingLocalRepData(AttackableUnit *building,
                                    CReplInfo32 *ri, ReplicationManager* manager);
    static void FillBasicLocalRepDataTower(CharacterIntermediateRep *building,
                                     CReplInfo32 *ri, ReplicationManager* manager);
    static void FillLocalRepData(AttackableUnit *unit, CharacterState *state,
                            CReplInfo32 *ri, ReplicationManager* manager);
    static void FillBasicMapRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                               ReplicationManager* manager);
    static void FillBasicLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                                 ReplicationManager* manager);
    static void FillHeroLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri, ReplicationManager* replicator);
    static void FillHeroMapRepData(CharacterIntermediateRep *charInter,  CReplInfo32 *ri, ReplicationManager* replicator);

};

#endif // REPLICATIONHELPER_H
