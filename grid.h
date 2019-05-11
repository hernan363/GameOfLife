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
  map<pair<int,int>,int> trueSlotsSecondary;
  map<pair<int,int>,int>::iterator iteratorPrimary;
  map<pair<int,int>,int>::iterator iteratorSecondary;


  int height;
  int width;
  int popPercent;
  int ranNum1;
  int ranNum2;

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
