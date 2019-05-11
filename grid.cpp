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

void grid::randomGenerateMap() {

  //percent becomes the number of living squares we have to generate
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

void grid::setGridSecondary() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      gridSecondary[i][j] = gridPrimary[i][j];
    }
  }
}

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
