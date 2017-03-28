#include <iostream>
#include <inttypes.h>
#include <string>
#include "nav/navgrid.h"
#include "content/manager.h"
#include "content/spelldata.h"
#include "content/itemdata.h"

using namespace std;

int main()
{
    Content::Manager man;
    man.setBasePaths({"C:/Games/lol-1.0.0.673"});
    Content::ItemData sunfire;
    sunfire.load(3068, man);
    cout<<sunfire.mFlatArmorMod<<endl;
    return 0;
}
