#ifndef MIRROR_CPP
#define MIRROR_CPP

#include "mirror.h"


mirror::mirror(){}
mirror::~mirror(){}
//the grid diagram with X representing a coordinate that is alive

//X-X--
//--X--
//-X-X-

//Iterates through the PrimaryMap to find nodes that are true
//then creates a 3 by 3 grid with the node at the center.
//It adds 1 to each neighbor that the grid has as long
//as the neighbor is within the restrictions of mirror mode.

//This is tricky because the walls reflect the coordinate back.
//My idea was to split the program into two parts.
//The first part of the program takes care of the mirror reflecting issues,
//then the second part runs classic mode to fill in the gaps.

//It looks for each of the corners and adds 3 to the corner for the
//surrounding neightbors.
//This is illustrated by the N's in the diagram.
//I add 1 to the J's because the N's at the end of the corner are
//neighboring the J's

//NN
//NXj--
// j---

//The next special condition are coordinates on the edge of the grid
//but inbetween the corners.
//The node is reflected off the mirror and affects the neighbor count
//of 3 coordinates which are
//the original coordinate and its two neighbors.
//If X is the coordinate that is alive, we add 1 to the neighbor
//count of both N's and X in the diagram

//--NXN--
//-------
//-------

//Notice how I am not adding anything to the neighbors below the targeted
//coordinate. This is because classic mode will target those neighbors in
//the second part.

//after all this the second part runs (classic mode)


map<pair<int,int>,int> mirror::mirrorNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;

  for(g1.it = g1.trueSlots.begin(); g1.it != g1.trueSlots.end(); ++g1.it) {
    if(g1.primaryG[g1.it->first.first][g1.it->first.second] == true) {
        if(g1.it->first.first == 0) {
          if(g1.it->first.second <= 0) {
            tempMap[make_pair(1,g1.it->first.second)] += 1;
            tempMap[make_pair(0,g1.it->first.second)] += 3;
            tempMap[make_pair(0,g1.it->first.second+1)] += 1;

          } else if(g1.it->first.second >= g1.width-1) {
            tempMap[make_pair(1,g1.it->first.second)] += 1;
            tempMap[make_pair(0,g1.it->first.second)] += 3;
            tempMap[make_pair(0,g1.it->first.second-1)] += 1;
          } else{
            for(int i = -1; i < 2; ++i) {
              tempMap[make_pair(0, g1.it->first.second+i)] += 1;
            }
          }
        } else if(g1.it->first.first == g1.height-1) {
          if(g1.it->first.second <= 0) {
            tempMap[make_pair(g1.it->first.first-1,g1.it->first.second)] += 1;
            tempMap[make_pair(g1.it->first.first,g1.it->first.second)] += 3;
            tempMap[make_pair(g1.it->first.first,g1.it->first.second+1)] += 1;

          } else if(g1.it->first.second >= g1.width-1) {
            tempMap[make_pair(g1.it->first.first-1,g1.it->first.second)] += 1;
            tempMap[make_pair(g1.it->first.first,g1.it->first.second)] += 3;
            tempMap[make_pair(g1.it->first.first,g1.it->first.second-1)] += 1;
          } else {
            for(int i = -1; i < 2; ++i) {
              tempMap[make_pair(g1.it->first.first, g1.it->first.second+i)] += 1;
            }
          }
        } else if(g1.it->first.second == 0 || g1.it->first.second == g1.width-1){
          for(int i = -1; i < 2; ++i) {
            tempMap[make_pair(g1.it->first.first+i,g1.it->first.second)] += 1;
          }
        }
      //classic mode
      for(int i = -1; i < 2; ++ i) {
        for( int j = -1; j < 2; ++j) {
          if( g1.it->first.first+i < 0 || g1.it->first.first+i >= g1.height) {
            continue;
          } else if( g1.it->first.second+j < 0 || g1.it->first.second+j >= g1.width) {
          continue;
          } else if( g1.it->first.first+i == g1.it->first.first && g1.it->first.second + j ==  g1.it->first.second) {
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
