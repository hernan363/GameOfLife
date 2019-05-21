#ifndef DOUGHNUT_CPP
#define DOUGHNUT_CPP

#include "doughnut.h"

doughnut::doughnut(){}
doughnut::~doughnut(){}

//the grid diagram with X representing a coordinate that is alive

//X-X--
//--X--
//-X-X-

//Iterates through the PrimaryMap to find nodes that are true
//then creates a 3 by 3 grid with the main coordinate at the center.
//It adds 1 to each point of the grid has as long
//as the points are within the restrictions of doughnut mode.

//This is tricky because the idea is to be a circular dougnut so it wraps
//around to make a continuous loop.
//My idea was to create if statements that filter out the special conditions
//then run a standard simulation.
//A standard simulation adds 1 to every single neighbor around the
//coordinate.
//The special conditions are as such in the examples below.
//They consist of the corners (example 1) and the edges (example 2).
//The corners have to wrap around to the opposite sides.
//Add 1 to the neighbor count of the N's in the diagram.

//X is the targeted coordinate.
//N is the neighbor to the target.

//corners
//example 1:
//N----NX
//-----NN
//N------
//NN----N

//edges
//example 2:     example 3:
//--NXN--        -------
//--NNN--        NN----N
//-------        XN----N
//--NNN--        NN----N


map<pair<int,int>,int> doughnut::doughnutNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;

  for(g1.it = g1.trueSlots.begin(); g1.it != g1.trueSlots.end(); ++g1.it) {
    if(g1.primaryG[g1.it->first.first][g1.it->first.second] == true) {
      for(int i = -1; i < 2; ++ i) {
        for( int j = -1; j < 2; ++j) {
          //above 0,0
            if (g1.it->first.first+i == g1.it->first.first && g1.it->first.second+j == g1.it->first.second) {
            } else if (g1.it->first.first+i >= g1.height) { //height,0 && height,width
              if (g1.it->first.second+j < 0) {
                tempMap[make_pair(0,g1.width+j)] += 1;
              } else if (g1.it->first.second+j >= g1.width) {
                tempMap[make_pair(0,0)] += 1;
              } else {
                tempMap[make_pair(0,g1.it->first.second+j)] += 1;
              }
            } else if (g1.it->first.first+i < 0) { // 0,width && 0,0
              if (g1.it->first.second+j >= g1.width) {
                tempMap[make_pair(g1.height+i,0)] += 1;
              } else if (g1.it->first.second+j < 0) {
                tempMap[make_pair(g1.height+i,g1.width+j)] += 1;
              } else {
                tempMap[make_pair(g1.height-1,g1.it->first.second+j)] += 1;
              }
            } else if (g1.it->first.second+j < 0 ) { //left side
              tempMap[make_pair(g1.it->first.first+i, g1.width+j)] += 1;
            } else if (g1.it->first.second+j >= g1.width) { //right side
              tempMap[make_pair(g1.it->first.first+i, 0)] += 1;
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
