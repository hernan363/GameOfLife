#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <map>
#include "grid.h"

using namespace std;

class fileReader {
  private:

    string fileName;
    ifstream myFile;
    string line;
  public:
    fileReader();

    fileReader(string targetFile);
    ~fileReader();
    grid readFile(grid thisGrid, ifstream& myFile);
    void outputFile(grid thisGrid, ofstream& myFile);
    // grid gridToFalse(int height, int width);



};


#endif
