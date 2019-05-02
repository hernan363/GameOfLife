#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include "grid.h"

using namespace std;

class doughnut {
public:
  map<pair<int,int>,int> doughnutNeighborCount(grid g1);
  doughnut();
  ~doughnut();
private:

};

#endif
