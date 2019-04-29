#ifndef GRID_H
#define GRID_H

#include <map>
#include <iostream>

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

  grid();
  ~grid();

  void printAll();
  void mapToGrid();
  void setGridsToFalse();


private:

};

#endif
