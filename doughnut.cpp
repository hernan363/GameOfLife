#ifndef DOUGHNUT_CPP
#define DOUGHNUT_CPP

#include "doughnut.h"

doughnut::doughnut(){}
doughnut::~doughnut(){}


map<pair<int,int>,int> doughnut::doughnutNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;
  
  for(g1.iteratorPrimary = g1.trueSlotsPrimary.begin(); g1.iteratorPrimary != g1.trueSlotsPrimary.end(); ++g1.iteratorPrimary) {
    if(g1.gridPrimary[g1.iteratorPrimary->first.first][g1.iteratorPrimary->first.second] == true) {
      for(int i = -1; i < 2; ++ i) {
        for( int j = -1; j < 2; ++j) {
          //above 0,0
            if( g1.iteratorPrimary->first.first+i == g1.iteratorPrimary->first.first && g1.iteratorPrimary->first.second+j == g1.iteratorPrimary->first.second) {

            } else if( g1.iteratorPrimary->first.first+i >= g1.height) { //above height,0 && height,width

              if(g1.iteratorPrimary->first.second+j < 0) {
                tempMap[make_pair(0,g1.width+j)] += 1;
              }
              else if(g1.iteratorPrimary->first.second+j >= g1.width) {
                tempMap[make_pair(0,0)] += 1;
              }
              else {
                tempMap[make_pair(0,g1.iteratorPrimary->first.second+j)] += 1;
              }
            } else if( g1.iteratorPrimary->first.first+i < 0) { // 0,width && 0,0
              if(g1.iteratorPrimary->first.second+j >= g1.width) {
                tempMap[make_pair(g1.height+i,0)] += 1;
              } else if(g1.iteratorPrimary->first.second+j < 0) {
                tempMap[make_pair(g1.height+i,g1.width+j)] += 1;
              } else {
                tempMap[make_pair(g1.height-1,g1.iteratorPrimary->first.second+j)] += 1;
              }
            } else if(g1.iteratorPrimary->first.second+j < 0 ) { //left side
              tempMap[make_pair(g1.iteratorPrimary->first.first+i, g1.width+j)] += 1;
            } else if(g1.iteratorPrimary->first.second+j >= g1.width) { //right side
              tempMap[make_pair(g1.iteratorPrimary->first.first+i, 0)] += 1;
            } else {
              tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] += 1;
            }
          }
        }
      }
    }
  return tempMap;
}
#endif
