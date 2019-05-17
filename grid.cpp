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
  gridPrimary = new bool*[height];
  gridSecondary = new bool*[height];

  for(int i = 0; i < height; ++i) {
    gridPrimary[i] = new bool[width];
    gridSecondary[i] = new bool[width];

    for(int j = 0; j < width; ++j){
      gridPrimary[i][j] = false;
      gridSecondary[i][j] = false;
    }
  }
}

//iterates through the map with all the alive coordinates
//changes the primary grid according to the neighbor count
void grid::mapToGrid(){
  for(iteratorPrimary = trueSlotsPrimary.begin(); iteratorPrimary != trueSlotsPrimary.end();++iteratorPrimary) {
    if(iteratorPrimary->second <= 1 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = false;
    } else if(iteratorPrimary->second == 3 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = true;
    } else if(iteratorPrimary->second >= 4 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = false;
    }
  }
}

//randomly generates coordinates that are alive
//then changes the primary grid accordingly
void grid::randomGenerateMap() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      if(rand() % 100+1 <= popPercent) {
        trueSlotsPrimary[make_pair(j,i)] = 3;
        gridPrimary[i][j] = true;

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
      if(gridPrimary[i][j] != gridSecondary[i][j]) {
        return false;
      }
    }
  }
  return true;
}

//transfers the primary grid to the secondary grid
void grid::setGridSecondary() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      gridSecondary[i][j] = gridPrimary[i][j];
    }
  }
}

//prints the primary grid
void grid::printAll(){
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j){
      if(gridPrimary[i][j] == true) {
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
