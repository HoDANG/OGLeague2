#include <iostream>
#include <inttypes.h>
#include <string>
#include "nav/navgrid.h"
#include "content/manager.h"
#include "content/spelldata.h"

using namespace std;

int main()
{
    Content::Manager man;
    man.setBasePaths({"C:/Games/lol-1.0.0.673"});
    Content::SpellData abp;
    abp.load("AbponsPaperFan", man);
    cout<<abp.mMissileEffectName<<endl;
    return 0;
}
