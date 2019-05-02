#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"


classic::classic(){}
classic::~classic(){}

map<pair<int,int>,int> classic::classicNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;
  map<pair<int,int>,int>::iterator tempMapIt;


  for(g1.iteratorPrimary = g1.trueSlotsPrimary.begin(); g1.iteratorPrimary != g1.trueSlotsPrimary.end(); ++g1.iteratorPrimary) {
    if(g1.gridPrimary[g1.iteratorPrimary->first.first][g1.iteratorPrimary->first.second] == true) {

      for(int i = -1; i < 2; ++ i) {
        for( int j = -1; j < 2; ++j) {

            if( g1.iteratorPrimary->first.first+i < 0 || g1.iteratorPrimary->first.first+i >= g1.height) {
              continue;
            }

            else if( g1.iteratorPrimary->first.second+j < 0 || g1.iteratorPrimary->first.second+j >= g1.width) {
              continue;
            }

            else if( g1.iteratorPrimary->first.first+i == g1.iteratorPrimary->first.first && g1.iteratorPrimary->first.second + j ==  g1.iteratorPrimary->first.second) {
              continue;
            }

            else {
              if(tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] != false) {
                tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] += 1;
                // cout << "Added to the count!!!" << endl;
              }
              //if there is no entry inside the tempMap
              else {
                tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] = 1;
                // cout << "created a new pair!!!"<< endl;
              }
            }
          }
        }
    }
  }
  // for(tempMapIt = tempMap.begin(); tempMapIt != tempMap.end();++tempMapIt) {
  //   cout << tempMapIt->first.first << " : " << tempMapIt->first.second <<  " : " << tempMapIt->second << endl;
  // }
  return tempMap;
}


#endif
