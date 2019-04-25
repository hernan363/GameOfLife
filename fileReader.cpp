#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"

fileReader::fileReader(){
  const string fileName = "";
  line = "";
  height = 0;

}

fileReader::fileReader(string targetFile) {
  const string fileName = targetFile;
  line = "";
  height = 0;
  width = 0;
}

fileReader::~fileReader(){}
//Opens a file and creates the grid in the file into an array
map<int,int,bool> fileReader::readFile() {
  map<int,int,bool> grid;
  map<int,int,bool>::iterator it = grid.begin();
  //height
  getline(myFile, line);

  //width
  getline(myFile, line);

  myFile.open(fileName); //opening file
  //O(N*M) where N is the number of lines and M is the length of the Line
  for(int i = 0; i < height; ++i) {
    for(int i = 0; i < line.length(); ++i) {
      if(line[i] == '-') {
        grid[height][i] == false;
      }
      else {
        grid[height][i] == true;
      }
    }
    height += 1;
  }
  myFile.close(); //closing file
  return grid;
}


//sets all values to false;
map<int,int,bool> fileReader::gridToFalse(int height, int width) {
  bool** newGrid[height];
  for(int i = 0; i  < height; ++i) {
    newGrid[i] = new bool[width];
    for(int j =0; j < width; ++j) {
      newGrid[i][j] = false;
    }
  }
}


#endif
