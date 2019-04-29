#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

classic::classic(){}
classic::~classic(){}

map<pair<int,int>,int> neighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;
  map<pair<int,int>,int>::iterator tempMapIt;


  for(g1.iteratorPrimary = g1.trueSlotsPrimary.begin(); g1.iteratorPrimary != g1.trueSlotsPrimary.end(); ++g1.iteratorPrimary) {

    for(int i = 0; i < 3; ++ i) {
      for( int j = 0; j < 3; ++j) {

        if(g1.gridPrimary[g1.iteratorPrimary->first.first+i][g1.iteratorPrimary->first.second+j] == true) {
            if( g1.iteratorPrimary->first.first < 0 || g1.iteratorPrimary->first.first >= g1.height) {
              continue;
            }

            else if( g1.iteratorPrimary->first.second+i < 0 || g1.iteratorPrimary->first.second+j >= g1.width) {
              continue;
            }

            else {
              if(tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] != false) {
                tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] += 1;
              }
              //if there is no entry inside the tempMap
              else {
                tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] = 1;
              }
            }
        }
      }
    }
  }
  return tempMap;
}


#endif
