#include "scripthelper.h"
#include "scripthelperbb.h"
#include "scripthelperdamage.h"
#include "scripthelperextra.h"
#include "scripthelperspells.h"

std::vector<AiTimer *> *ScriptHelper::mLevelTimers = nullptr;
std::vector<NeutralTimer *> *ScriptHelper::mNeutralTimers = nullptr;

bool ScriptHelper::LoadLuaFile(std::string name, sol::state &state)
{
    if(state.load(r3dFileManager::getFilePath(name+"obj")))
    {
        return true;
    }
    return false;
}

void ScriptHelper::RegisterGlobals(sol::state &state)
{
    state["PHYSICAL_DAMAGE"] = 0;
    state["MAGIC_DAMAGE"] = 1;
    state["TRUE_DAMAGE"] = 2;
    state["HIT_Normal"] = 0;
    state["HIT_Critical"] = 1;
    state["HIT_Miss"] = 3;
    state["HIT_Dodge"] = 2;

    state["Log"] = &ScriptHelper::Log;
    state["GetPosition"] = &ScriptHelper::GetPosition;
    state["SetPosition"] = &ScriptHelper::SetPosition;
    state["FacePosition"] = &ScriptHelper::FacePosition;
    state["IncPosition"] = &ScriptHelper::IncPosition;
    state["IncGold"] = &ScriptHelper::IncGold;
    state["GiveExpToNearHeroesFromNeutral"] = &ScriptHelper::GiveExpToNearHeroesFromNeutral;
    state["GetNormalizedPositionDelta"] = &ScriptHelper::GetNormalizedPositionDelta;
    state["Multiply3dPointByScalar"] = &ScriptHelper::Multiply3dPointByScalar;
    state["DistPoint3DSegment3D"] = &ScriptHelper::DistPoint3DSegment3D;
    state["Add3dPoints"] = &ScriptHelper::Add3dPoints;
    state["GetTeamID"] = &ScriptHelper::GetTeamID;
    state["GetID"] = &ScriptHelper::GetID;
    state["MakeSay"] = &ScriptHelper::MakeSay;
    state["GetHQType"] = &ScriptHelper::GetHQType;
    state["GetDampenerType"] = &ScriptHelper::GetDampenerType;
    state["IsObjectHero"] = &ScriptHelper::IsObjectHero;
    state["IsObjectAI"] = &ScriptHelper::IsObjectAI;
    state["IsTurretAI"] = &ScriptHelper::IsTurretAI;
    state["GetObjectLaneId"] = &ScriptHelper::GetObjectLaneId;
    state["GetTurretPosition"] = &ScriptHelper::GetTurretPosition;
    state["GetLinkedBarrack"] = &ScriptHelper::GetLinkedBarrack;
    state["GetDampener"] = &ScriptHelper::GetDampener;
    state["IsDampener"] = &ScriptHelper::IsDampener;
    state["SetDampenerState"] = &ScriptHelper::SetDampenerState;
    state["GetLane"] = &ScriptHelper::GetLane;
    state["EndGame"] = &ScriptHelper::EndGame;
    state["InitTimer"] = &ScriptHelper::InitTimer;
    state["AssignTeamGold"] = &ScriptHelper::AssignTeamGold;
    state["luaNeutralInitTimer"] = &ScriptHelper::luaNeutralInitTimer;
    state["SpawnNeutralMinion"] = &ScriptHelper::SpawnNeutralMinion;
    state["LoadScriptIntoScript"] = &ScriptHelper::LoadScriptIntoScript;
    state["Make3DPoint"] = &ScriptHelper::Make3DPoint;
    state["GetTurret"] = &ScriptHelper::GetTurret;
    state["GetBarracks"] = &ScriptHelper::GetBarracks;
    state["SetDisableMinionSpawn"] = &ScriptHelper::SetDisableMinionSpawn;
    state["SetBarracksEnabled"] = &ScriptHelper::SetBarracksEnabled;
    state["GetHQ"] = &ScriptHelper::GetHQ;
    state["GetTutorialPlayer"] = &ScriptHelper::GetTutorialPlayer;
    state["CreateGameObject"] = &ScriptHelper::CreateGameObject;
    state["PreloadCharacter"] = &ScriptHelper::PreloadCharacter;
    state["PreloadSpell"] = &ScriptHelper::PreloadSpell;
    state["PreloadParticle"] = &ScriptHelper::PreloadParticle;
    state["GetHashedGameObjName"] = &ScriptHelper::GetHashedGameObjName;
    state["SetLaneAffinity"] = &ScriptHelper::SetLaneAffinity;
    state["CreateChildTurret"] = &ScriptHelper::CreateChildTurret;
    state["ToggleInputLockingFlag"] = &ScriptHelper::ToggleInputLockingFlag;
    state["SetInputLockingFlag"] = &ScriptHelper::SetInputLockingFlag;
    state["ToggleFogOfWar"] = &ScriptHelper::ToggleFogOfWar;
    state["ToggleFogOfWarOn"] = &ScriptHelper::ToggleFogOfWarOn;
    state["SetCircularCameraRestriction"] = &ScriptHelper::SetCircularCameraRestriction;
    state["LockCamera"] = &ScriptHelper::LockCamera;
    state["PauseGame"] = &ScriptHelper::PauseGame;
    state["ResumeGame"] = &ScriptHelper::ResumeGame;
    state["PlayTutorialAudioEvent"] = &ScriptHelper::PlayTutorialAudioEvent;
    state["GetUnitSkinName"] = &ScriptHelper::GetUnitSkinName;
    state["IncExp"] = &ScriptHelper::IncExp;
    state["GetTime"] = &ScriptHelper::GetTime;
    state["_ALERT"] = &ScriptHelper::_ALERT;
    state["GetTotalTeamMinionsSpawned"] = &ScriptHelper::GetTotalTeamMinionsSpawned;
}

void ScriptHelper::InitState(sol::state &state)
{
    ScriptHelper::RegisterGlobals(state);
    ScriptHelperBB::RegisterGlobals(state);
    ScriptHelperDamage::RegisterGlobals(state);
    ScriptHelperExtra::RegisterGlobals(state);
    ScriptHelperSpells::RegisterGlobals(state);
    ScriptHelper::LoadLuaFile("DATA/BuildingBlocks/BuildingBlocksBase.lua", state);
    ScriptHelper::LoadLuaFile("DATA/BuildingBlocks/BBLuaConversionLibrary.lua", state);
}
