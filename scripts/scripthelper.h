#ifndef SCRIPTHELPER_H
#define SCRIPTHELPER_H

#include <vector>
#include "dep/sol.hpp"
#include "dep/r3d.hpp"
#include "aitimer.h"
#include "neutraltimer.h"

struct ScriptHelper
{
    static std::vector<AiTimer *> *mLevelTimers;
    static std::vector<NeutralTimer *> *mNeutralTimers;
    static std::string mMapName;

    static bool LoadLuaFile(std::string name, sol::state_view state);
    static void RegisterGlobals(sol::global_table state);

    static void InitState(sol::state_view state);

    static bool IsDampener(sol::stack_object object);
    static bool IsObjectAI(sol::stack_object obj);
    static bool IsObjectHero(sol::stack_object obj);
    static bool IsTurretAI(sol::stack_object obj);
    static float DistPoint3DSegment3D(sol::stack_object pos, sol::stack_object point1, sol::stack_object point2);
    static float GetTime();
    static int GetDampenerType(sol::stack_object obj);
    static int GetHQType(sol::stack_object obj);
    static int GetHashedGameObjName(std::string string);
    static int GetID(sol::stack_object owner);
    static int GetLane(sol::stack_object laneBuilding);
    static int GetObjectLaneId(sol::stack_object obj);
    static int GetTeamID(sol::stack_object owner);
    static int GetTotalTeamMinionsSpawned();
    static int GetTurretPosition(sol::stack_object obj);
    static sol::object Add3dPoints(sol::stack_object point1, sol::stack_object point2);
    static sol::object GetBarracks(int team, int lane, sol::this_state thisState);
    static sol::object GetDampener(int team, int lane, sol::this_state thisState);
    static sol::object GetHQ(int team, sol::this_state thisState);
    static sol::object GetLinkedBarrack(sol::stack_object dampener, sol::this_state thisState);
    static sol::object GetNormalizedPositionDelta(sol::stack_object endObj, sol::stack_object startObj, bool shouldIgnoreY, sol::this_state thisState);
    static sol::object GetPosition(sol::stack_object owner, sol::this_state thisState);
    static sol::object GetTurret(int team, int lane, int position, sol::this_state thisState);
    static sol::object GetTutorialPlayer();
    static r3dPoint3D Make3DPoint(float x, float y, float z, sol::this_state thisState);
    static sol::object Multiply3dPointByScalar(sol::stack_object point, float scalar, sol::this_state thisState);
    static std::string GetUnitSkinName(sol::stack_object unit);
    static void AssignTeamGold(int teamID, float gold);
    static void CreateChildTurret(std::string name, std::string skinName, int team, int turretIndex, int lane);
    static void CreateGameObject(std::string name, std::string fileName, sol::stack_object position);
    static void EndGame(int winningTeam);
    static void FacePosition(sol::stack_object target, sol::stack_object targetPos);
    static void GiveExpToNearHeroesFromNeutral(sol::stack_object killer, float exp, sol::stack_object position, float radius);
    static void IncExp(sol::stack_object champion, float exp);
    static void IncGold(sol::stack_object object, float goldAmount);
    static void IncPosition(sol::stack_object owner, sol::stack_object delta);
    static void InitTimer(std::string timerName, float delay, bool repeat);
    static void LoadScriptIntoScript(std::string name, sol::this_state state);
    static void LockCamera(bool lock);
    static void Log(std::string message);
    static void MakeSay(sol::stack_object talker, std::string message);
    static void PauseGame();
    static void PlayTutorialAudioEvent(std::string eventID, std::string luaCallbackName);
    static void PreloadCharacter(std::string name);
    static void PreloadParticle(std::string name);
    static void PreloadSpell(std::string name);
    static void ResumeGame();
    static void SetBarracksEnabled(sol::stack_object barrack, bool state);
    static void SetCircularCameraRestriction(sol::stack_object center, float radius);
    static void SetDampenerState(sol::object dampener, int state);
    static void SetDisableMinionSpawn(sol::stack_object barrack, float respawnTime);
    static void SetInputLockingFlag(int flag, bool flagValue);
    static void SetLaneAffinity(std::string name, int turretIndex, int lane);
    static void SetPosition(sol::stack_object target, sol::stack_object targetPos);
    static void SpawnNeutralMinion(sol::object neutralCamp, int groupNumber, int groupIndex, int nameIndex);
    static void ToggleFogOfWar();
    static void ToggleFogOfWarOn();
    static void ToggleInputLockingFlag(int flag);
    static void _ALERT(std::string message);
    static void luaNeutralInitTimer(sol::object functionName, float delay, bool repeat);
};

#endif // SCRIPTHELPER_H
