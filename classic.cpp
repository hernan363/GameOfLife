#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

classic::classic(){}
classic::~classic(){}

//Iterates through the PrimaryMap to find nodes that are true
//then creates a 3 by 3 grid with the node at the center
//it adds 1 to each neighbor that the grid has as long
//as the neighbor is within the restrictions of classic mode
map<pair<int,int>,int> classic::classicNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;

  for (g1.it = g1.trueSlots.begin(); g1.it != g1.trueSlots.end(); ++g1.it) {
    if (g1.primaryG[g1.it->first.first][g1.it->first.second] == true) {
      for (int i = -1; i < 2; ++ i) {
        for (int j = -1; j < 2; ++j) {
            if (g1.it->first.first+i < 0 || g1.it->first.first+i >= g1.height) {
              continue;
            } else if (g1.it->first.second+j < 0 || g1.it->first.second+j >= g1.width) {
              continue;
            } else if (g1.it->first.first+i == g1.it->first.first && g1.it->first.second + j ==  g1.it->first.second) {
              continue;
            } else {
              tempMap[make_pair(g1.it->first.first+i,g1.it->first.second+j)] += 1;
            }
          }
        }
    }
  }
  return tempMap;
}
#endif
