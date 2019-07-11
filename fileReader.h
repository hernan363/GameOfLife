#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <map>
#include "grid.h"

using namespace std;

class fileReader {
  private:
    string fileName;
    ifstream myFile;
    string line;
    int j;
  public:
    fileReader();
    ~fileReader();
    grid readFile(grid thisGrid, ifstream& myFile);
};
#endif
