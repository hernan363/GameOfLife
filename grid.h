#ifndef GRID_H
#define GRID_H

#include <map>
#include <iostream>

using namespace std;

class grid {
public:
  bool** gridPrimary;
  bool** gridSecondary;
  map<pair<int,int>,bool> trueSlots;
  map<pair<int,int>,bool>::iterator iterator;


  int height;
  int width;

  grid();
  ~grid();

  void printAll();
  void fillGridWithTrue();
  void setGridsToFalse();


private:

};

#endif
