#ifndef GRID_CPP
#define GRID_CPP

#include "grid.h"

grid::grid() {
  height = 0;
  width = 0;
}

grid::~grid() {}


//setting up the grids
///////////////////////////////////////////////////////////////
void grid::setGridsToFalse() {
  gridPrimary = new bool*[height];
  gridSecondary = new bool*[height];

  cout << height << width << "dfsdafsd" << endl;
  for(int i = 0; i < height; ++i) {
    gridPrimary[i] = new bool[width];
    gridSecondary[i] = new bool[width];
    
    for(int j = 0; j < width; ++j){
      gridPrimary[i][j] = false;
      gridSecondary[i][j] = false;
    }
  }
}

void grid::fillGridWithTrue(){
  for(iterator = trueSlots.begin(); iterator != trueSlots.end();++iterator) {
    gridPrimary[iterator->first.first][iterator->first.second] = true;
  }
}

///////////////////////////////////////////////////////////////////////





void grid::printAll(){
  for(iterator = trueSlots.begin(); iterator != trueSlots.end();++iterator) {
    cout << iterator->first.first << " : " << iterator->first.second << endl;
  }
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j){
      cout << gridPrimary[i][j];
    }
    cout <<endl;
  }
}

#endif
