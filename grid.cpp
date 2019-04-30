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

void grid::mapToGrid(){
  for(iteratorPrimary = trueSlotsPrimary.begin(); iteratorPrimary != trueSlotsPrimary.end();++iteratorPrimary) {
    if(iteratorPrimary->second <= 1 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = false;
    }

    else if(iteratorPrimary->second == 3 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = true;

    }

    else if(iteratorPrimary->second >= 4 ) {
      gridPrimary[iteratorPrimary->first.first][iteratorPrimary->first.second] = false;
    }
  }
}

///////////////////////////////////////////////////////////////////////





void grid::printAll(){
  // for(iteratorPrimary = trueSlotsPrimary.begin(); iteratorPrimary != trueSlotsPrimary.end();++iteratorPrimary) {
  //   cout << iteratorPrimary->first.first << " : " << iteratorPrimary->first.second <<  " : " << iteratorPrimary->second << endl;
  // }
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j){
      if(gridPrimary[i][j] == true) {
        cout << "X";

      }
      else {
        cout << "-";
      }
    }
    cout <<endl;
  }
}

#endif
