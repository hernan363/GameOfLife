#ifndef GRID_H
#define GRID_H

#include <map>
#include <iostream>
#include <stdlib.h>

using namespace std;

class grid {
public:
  bool** gridPrimary;
  bool** gridSecondary;
  map<pair<int,int>,int> trueSlotsPrimary;
  map<pair<int,int>,int>::iterator iteratorPrimary;

  int height;
  int width;
  int popPercent;

  grid();
  ~grid();
  void setGridSecondary();

  void printAll();
  void mapToGrid();
  void setGridsToFalse();
  bool compareGrids();
  void randomGenerateMap();

private:

};

#endif
