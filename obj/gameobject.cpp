#include "gameobject.h"
#include "crc32.hpp"

GameObject::GameObject(World *world) : pWorld(world)
{

}

uint32_t GameObject::objFlags() const
{
    return mObjFlags;
}

void GameObject::setObjFlags(const uint32_t &objFlags)
{
    mObjFlags = objFlags;
}


void GameObject::assignIDByName()
{
    CRC32 crc;
    uint32_t id = crc.GetHash(mName.c_str());
    setNetworkID(0xFF000000 | id);
}

void GameObject::assignID()
{
    setNetworkID(pWorld->objectmanager().getNextID());
}

uint32_t GameObject::networkID() const
{
    return mNetworkID;
}

void GameObject::setNetworkID(const uint32_t &networkID)
{
    mNetworkID = networkID;
    OnNetworkIDChanged();
}

void GameObject::OnNetworkIDChanged()
{
    if(pWorld != nullptr)
        pWorld->objectmanager().add(this);
}

uint32_t GameObject::ownerID() const
{
    return mOwnerID;
}

void GameObject::setOwnerID(const uint32_t &ownerID)
{
    mOwnerID = ownerID;
}

bool GameObject::active() const
{
    return mActive;
}

void GameObject::setActive(bool active)
{
    mActive = active;
}

bool GameObject::noStaticCollisions() const
{
    return mNoStaticCollisions;
}

void GameObject::setNoStaticCollisions(bool noStaticCollisions)
{
    mNoStaticCollisions = noStaticCollisions;
}

bool GameObject::dead() const
{
    return mDead;
}

void GameObject::setDead(bool dead)
{
    mDead = dead;
}

bool GameObject::zombie() const
{
    return mZombie;
}

void GameObject::setZombie(bool zombie)
{
    mZombie = zombie;
}

bool GameObject::becomeZombie() const
{
    return mBecomeZombie;
}

void GameObject::setBecomeZombie(bool becomeZombie)
{
    mBecomeZombie = becomeZombie;
}

float GameObject::lastTookDamageTime() const
{
    return mLastTookDamageTime;
}

void GameObject::setLastTookDamageTime(float lastTookDamageTime)
{
    mLastTookDamageTime = lastTookDamageTime;
}

r3dPoint3D GameObject::position() const
{
    return mPosition;
}

void GameObject::setPosition(const r3dPoint3D &position)
{
    mPosition = position;
}

r3dPoint3D GameObject::velocity() const
{
    return mVelocity;
}

void GameObject::setVelocity(const r3dPoint3D &velocity)
{
    mVelocity = velocity;
}

r3dPoint3D GameObject::accelaration() const
{
    return mAccelaration;
}

void GameObject::setAccelaration(const r3dPoint3D &accelaration)
{
    mAccelaration = accelaration;
}

r3dPoint3D GameObject::orientation() const
{
    return mOrientation;
}

void GameObject::setOrientation(const r3dPoint3D &orientation)
{
    mOrientation = orientation;
}

r3dBox3D GameObject::bBox() const
{
    return mBBox;
}

void GameObject::setBBox(const r3dBox3D &bBox)
{
    mBBox = bBox;
}

team_e GameObject::getTeam() const
{
    return Team;
}

void GameObject::setTeam(const team_e &value)
{
    Team = value;
}

std::string GameObject::getName() const
{
    return mName;
}

void GameObject::setName(const std::string &name)
{
    mName = name;
}

void GameObject::update()
{

}

bool GameObject::Load(std::string name)
{
    mName = name;
    return true;
}
