#ifndef GRID_CPP
#define GRID_CPP

#include "grid.h"

grid::grid() {
  height = 0;
  width = 0;
  popPercent = 0;
}

grid::~grid() {}

//setting up the grids///////////////////////////////////////////////////////////////
void grid::setGridsToFalse() {
  primaryG = new bool*[height];
  secondaryG = new bool*[height];

  for(int i = 0; i < height; ++i) {
    primaryG[i] = new bool[width];
    secondaryG[i] = new bool[width];

    for(int j = 0; j < width; ++j){
      primaryG[i][j] = false;
      secondaryG[i][j] = false;
    }
  }
}

//iterates through the map with all the alive coordinates
//changes the primaryG grid according to the neighbor count
void grid::mapToGrid(){
  for(it = trueSlots.begin(); it != trueSlots.end();++it) {
    if(it->second <= 1 ) {
      primaryG[it->first.first][it->first.second] = false;
    } else if(it->second == 3 ) {
      primaryG[it->first.first][it->first.second] = true;
    } else if(it->second >= 4 ) {
      primaryG[it->first.first][it->first.second] = false;
    }
  }
}

//randomly generates coordinates that are alive
//then changes the primary grid accordingly
void grid::randomGenerateMap() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      if(rand() % 100+1 <= popPercent) {
        trueSlots[make_pair(j,i)] = 3;
        primaryG[i][j] = true;

      }
    }
  }
}

///////////////////////////////////////////////////////////////////////

//compares the primary and secondary grid to
//make sure they are not the same
bool grid::compareGrids() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      if(primaryG[i][j] != secondaryG[i][j]) {
        return false;
      }
    }
  }
  return true;
}

//transfers the primary grid to the secondary grid
void grid::setSecondaryGrid() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      secondaryG[i][j] = primaryG[i][j];
    }
  }
}

//prints the primary grid
void grid::printAll(){
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j){
      if(primaryG[i][j] == true) {
        cout << "X";
      } else {
        cout << "-";
      }
    }
    cout << endl;
  }
  cout << endl;
}


#endif
