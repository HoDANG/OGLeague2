#include <iostream>
#include <inttypes.h>
#include <string>
#include "nav/navgrid.h"

using namespace std;

int main()
{
    NavGrid grid;
    grid.load("v2.aimesh_ngrid");

    return 0;
}
