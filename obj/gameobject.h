#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <inttypes.h>
#include <string>
#include "../dep/r3d.hpp"
#include "../common/team_e.h"
#include "../rep/replicationmanager.h"

enum EGameObjectFlags
{
  OBJFLAG_IgnoreCollisionOnPlacement = 0x1,
  OBJFLAG_CollideNever = 0x2,
  OBJFLAG_SkipCastRay = 0x10,
  OBJFLAG_SkipDraw = 0x20,
  OBJFLAG_UserCastRay = 0x80,
  OBJFLAG_SkipUpdate = 0x100,
  OBJFLAG_NotifyOnEnterExit = 0x200,
  OBJFLAG_JustCreated = 0x100000,
  OBJFLAG_DefaultObject = 0x200000,
};


namespace Game {
class World;
class GameObject
{
protected:
    uint32_t mObjFlags = 2;
    uint32_t mNetworkID = 0;
    uint32_t mOwnerID = 0;
    bool mActive = true;
    bool mNoStaticCollisions = true;
    bool mDead = false;
    bool mZombie = false;
    bool mBecomeZombie = false;
    float mLastTookDamageTime = 0.0f;
    r3dPoint3D mPosition = { 0.0f, 0.0f, 0.0f };
    r3dPoint3D mVelocity = { 0.0f, 0.0f, 0.0f };
    r3dPoint3D mAccelaration = { 0.0f, 0.0f, 0.0f };
    r3dPoint3D mOrientation = { 0.0f, 0.0f, 0.0f };
    r3dBox3D mBBox = {{0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }};
    team_e Team = team_e::TEAM_UNKNOWN;
    std::string mName;
public:
    GameObject(World* world);
    virtual bool Load(std::string name);
    uint32_t objFlags() const;
    void setObjFlags(const uint32_t &objFlags);
    World *pWorld = nullptr;
    void assignIDByName();
    void assignID();
    uint32_t networkID() const;
    void setNetworkID(const uint32_t &networkID);
    virtual void OnNetworkIDChanged();
    uint32_t ownerID() const;
    void setOwnerID(const uint32_t &ownerID);
    bool active() const;
    void setActive(bool active);
    bool noStaticCollisions() const;
    void setNoStaticCollisions(bool noStaticCollisions);
    bool dead() const;
    void setDead(bool dead);
    bool zombie() const;
    void setZombie(bool zombie);
    bool becomeZombie() const;
    void setBecomeZombie(bool becomeZombie);
    float lastTookDamageTime() const;
    void setLastTookDamageTime(float lastTookDamageTime);
    r3dPoint3D position() const;
    void setPosition(const r3dPoint3D &position);
    r3dPoint3D velocity() const;
    void setVelocity(const r3dPoint3D &velocity);
    r3dPoint3D accelaration() const;
    void setAccelaration(const r3dPoint3D &accelaration);
    r3dPoint3D orientation() const;
    void setOrientation(const r3dPoint3D &orientation);
    r3dBox3D bBox() const;
    void setBBox(const r3dBox3D &bBox);
    team_e getTeam() const;
    void setTeam(const team_e &value);
    std::string getName() const;
    void setName(const std::string &name);
};
}

#endif // GAMEOBJECT_H
