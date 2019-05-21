#ifndef GRID_H
#define GRID_H

#include <map>
#include <iostream>
#include <stdlib.h>

using namespace std;

class grid {
public:
  bool** primaryG; // Primary Grid
  bool** secondaryG; // Secondary Grid
  map<pair<int,int>,int> trueSlots; // Only the true slots
  map<pair<int,int>,int>::iterator it; // iterator

  int height;
  int width;
  int popPercent;

  grid();
  ~grid();
  void setSecondaryGrid();

  void printAll();
  void mapToGrid();
  void setGridsToFalse();
  bool compareGrids();
  void randomGenerateMap();

private:

};

#endif
