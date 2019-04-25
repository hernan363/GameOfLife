#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class fileReader {
  private:

    const string fileName;
    ifstream myFile;
    string line;
    int height;
    int width;
  public:
    fileReader(string targetFile);
    ~fileReader();
    map<int,int,bool> readFile();
    map<int,int,bool> gridToFalse(int height, int width);
    fileReader();



};


#endif
