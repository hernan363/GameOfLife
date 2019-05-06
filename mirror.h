#ifndef MIRROR_H
#define MIRROR_H

#include <iostream>
#include <map>
#include "grid.h"

using namespace std;

class mirror {
public:
  map<pair<int,int>,int> mirrorNeighborCount(grid g1);
  mirror();
  ~mirror();
private:
};

#endif
