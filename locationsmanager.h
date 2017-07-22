#ifndef LOCATIONSMANAGER_H
#define LOCATIONSMANAGER_H

class World;
class LocationsManager
{
private:
    World *pWorld;
public:
    LocationsManager(World* world);
};

#endif // LOCATIONSMANAGER_H
