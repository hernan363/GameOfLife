#ifndef MIRROR_CPP
#define MIRROR_CPP

#include "mirror.h"


mirror::mirror(){}
mirror::~mirror(){}

map<pair<int,int>,int> mirror::mirrorNeighborCount(grid g1) {
  map<pair<int,int>,int> tempMap;
  map<pair<int,int>,int>::iterator tempMapIt;


  for(g1.iteratorPrimary = g1.trueSlotsPrimary.begin(); g1.iteratorPrimary != g1.trueSlotsPrimary.end(); ++g1.iteratorPrimary) {
    if(g1.gridPrimary[g1.iteratorPrimary->first.first][g1.iteratorPrimary->first.second] == true) {
        if(g1.iteratorPrimary->first.first == 0) {
          if(g1.iteratorPrimary->first.second <= 0) {
            tempMap[make_pair(1,g1.iteratorPrimary->first.second)] += 1;
            tempMap[make_pair(0,g1.iteratorPrimary->first.second)] += 3;
            tempMap[make_pair(0,g1.iteratorPrimary->first.second+1)] += 1;

          }
          else if(g1.iteratorPrimary->first.second >= g1.width-1){
            tempMap[make_pair(1,g1.iteratorPrimary->first.second)] += 1;
            tempMap[make_pair(0,g1.iteratorPrimary->first.second)] += 3;
            tempMap[make_pair(0,g1.iteratorPrimary->first.second-1)] += 1;
          }

          else{
            for(int i = -1; i < 2; ++i) {
              tempMap[make_pair(0, g1.iteratorPrimary->first.second+i)] += 1;
            }
          }
        }

        else if(g1.iteratorPrimary->first.first == g1.height-1) {
          if(g1.iteratorPrimary->first.second <= 0) {
            tempMap[make_pair(g1.iteratorPrimary->first.first-1,g1.iteratorPrimary->first.second)] += 1;
            tempMap[make_pair(g1.iteratorPrimary->first.first,g1.iteratorPrimary->first.second)] += 3;
            tempMap[make_pair(g1.iteratorPrimary->first.first,g1.iteratorPrimary->first.second+1)] += 1;

          }
          else if(g1.iteratorPrimary->first.second >= g1.width-1){
            tempMap[make_pair(g1.iteratorPrimary->first.first-1,g1.iteratorPrimary->first.second)] += 1;
            tempMap[make_pair(g1.iteratorPrimary->first.first,g1.iteratorPrimary->first.second)] += 3;
            tempMap[make_pair(g1.iteratorPrimary->first.first,g1.iteratorPrimary->first.second-1)] += 1;
          }

          else{
            for(int i = -1; i < 2; ++i) {
              tempMap[make_pair(g1.iteratorPrimary->first.first, g1.iteratorPrimary->first.second+i)] += 1;
            }
          }
        }
        else if(g1.iteratorPrimary->first.second == 0 || g1.iteratorPrimary->first.second == g1.width-1){
          for(int i = -1; i < 2; ++i) {
            tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second)] += 1;
          }
        }

      //classic mode
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
            tempMap[make_pair(g1.iteratorPrimary->first.first+i,g1.iteratorPrimary->first.second+j)] += 1;
          }
        }
      }
    }
  }
  return tempMap;
}
#endif
