#include <iostream>
#include "obj/gameobject.h"
#include "scripthelper.h"

bool ScriptHelper::IsDampener(sol::stack_object object)
{
    return false;
}
bool ScriptHelper::IsObjectAI(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsObjectHero(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsTurretAI(sol::stack_object obj)
{
    return false;
}
float ScriptHelper::DistPoint3DSegment3D(sol::stack_object pos, sol::stack_object point1, sol::stack_object point2)
{
    return 0;
}
float ScriptHelper::GetTime()
{
    return 0;
}
int ScriptHelper::GetDampenerType(sol::stack_object obj)
{
    return 0;
}
int ScriptHelper::GetHQType(sol::stack_object obj)
{
    return 0;
}
int ScriptHelper::GetHashedGameObjName(std::string string)
{
    return 0;
}
int ScriptHelper::GetID(sol::stack_object owner)
{
    return 0;
}
int ScriptHelper::GetLane(sol::stack_object laneBuilding)
{
    return 0;
}
int ScriptHelper::GetObjectLaneId(sol::stack_object obj)
{
    return 0;
}
int ScriptHelper::GetTeamID(sol::stack_object owner)
{
    return 0;
}
int ScriptHelper::GetTotalTeamMinionsSpawned()
{
    return 0;
}
int ScriptHelper::GetTurretPosition(sol::stack_object obj)
{
    return 0;
}
sol::object ScriptHelper::Add3dPoints(sol::stack_object point1, sol::stack_object point2)
{
    return sol::nil;
}
sol::object ScriptHelper::GetBarracks(int team, int lane, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetDampener(int team, int lane, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetHQ(int team, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetLinkedBarrack(sol::stack_object dampener, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetNormalizedPositionDelta(sol::stack_object endObj, sol::stack_object startObj, bool shouldIgnoreY, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetPosition(sol::stack_object owner, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetTurret(int team, int lane, int position, sol::this_state thisState)
{
    return sol::nil;
}
sol::object ScriptHelper::GetTutorialPlayer()
{
    return sol::nil;
}
r3dPoint3D ScriptHelper::Make3DPoint(float x, float y, float z, sol::this_state thisState){
    r3dPoint3D point { x, y, z};
    return point;
}
sol::object ScriptHelper::Multiply3dPointByScalar(sol::stack_object point, float scalar, sol::this_state thisState)
{
    return sol::nil;
}
std::string ScriptHelper::GetUnitSkinName(sol::stack_object unit)
{
    return "";
}
void ScriptHelper::AssignTeamGold(int teamID, float gold)
{
}
void ScriptHelper::CreateChildTurret(std::string name, std::string skinName, int team, int turretIndex, int lane){
    std::cout<<"Creating child turre with: \""<<name
             <<"\"\n skin: \""<<skinName
             <<"\"\n for team: "<<team
             <<"\n on index: "<<turretIndex
             <<"\n on lane: "<<lane
             <<std::endl;
}

void ScriptHelper::CreateGameObject(std::string name, std::string fileName, sol::stack_object position)
{
}
void ScriptHelper::EndGame(int winningTeam)
{
}
void ScriptHelper::FacePosition(sol::stack_object target, sol::stack_object targetPos)
{
}
void ScriptHelper::GiveExpToNearHeroesFromNeutral(sol::stack_object killer, float exp, sol::stack_object position, float radius)
{
}
void ScriptHelper::IncExp(sol::stack_object champion, float exp)
{
}
void ScriptHelper::IncGold(sol::stack_object object, float goldAmount)
{
}
void ScriptHelper::IncPosition(sol::stack_object owner, sol::stack_object delta)
{
}
void ScriptHelper::InitTimer(std::string timerName, float delay, bool repeat)
{
}
void ScriptHelper::LoadScriptIntoScript(std::string name, sol::this_state state){
    if(!LoadLuaFile(name, state))
        if(!LoadLuaFile("LEVELS/"+mMapName+"/Scripts/"+name, state))
            LoadLuaFile("DATA/Scripts/"+name, state);
}
void ScriptHelper::LockCamera(bool lock)
{
}
void ScriptHelper::Log(std::string message)
{
}
void ScriptHelper::MakeSay(sol::stack_object talker, std::string message)
{
}
void ScriptHelper::PauseGame()
{
}
void ScriptHelper::PlayTutorialAudioEvent(std::string eventID, std::string luaCallbackName)
{
}
void ScriptHelper::PreloadCharacter(std::string name)
{
}
void ScriptHelper::PreloadParticle(std::string name)
{
}
void ScriptHelper::PreloadSpell(std::string name)
{
}
void ScriptHelper::ResumeGame()
{
}
void ScriptHelper::SetBarracksEnabled(sol::stack_object barrack, bool state)
{
}
void ScriptHelper::SetCircularCameraRestriction(sol::stack_object center, float radius)
{
}
void ScriptHelper::SetDampenerState(sol::object dampener, int state)
{
}
void ScriptHelper::SetDisableMinionSpawn(sol::stack_object barrack, float respawnTime)
{
}
void ScriptHelper::SetInputLockingFlag(int flag, bool flagValue)
{
}
void ScriptHelper::SetLaneAffinity(std::string name, int turretIndex, int lane)
{
}
void ScriptHelper::SetPosition(sol::stack_object target, sol::stack_object targetPos)
{
}
void ScriptHelper::SpawnNeutralMinion(sol::object neutralCamp, int groupNumber, int groupIndex, int nameIndex)
{
}
void ScriptHelper::ToggleFogOfWar()
{
}
void ScriptHelper::ToggleFogOfWarOn()
{
}
void ScriptHelper::ToggleInputLockingFlag(int flag)
{
}
void ScriptHelper::_ALERT(std::string message)
{
}
void ScriptHelper::luaNeutralInitTimer(sol::object functionName, float delay, bool repeat)
{
}
