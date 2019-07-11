#ifndef CLASSIC_H
#define CLASSIC_H

#include <map>
#include "grid.h"

using namespace std;

class classic {
public:

  classic();
  ~classic();

  map<pair<int,int>,int> classicNeighborCount(grid g1);



private:

};
#endif
