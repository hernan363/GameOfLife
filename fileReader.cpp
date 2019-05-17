#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"

fileReader::fileReader(){
  fileName = "";
  line = "";
  j = -1;
}

fileReader::~fileReader(){}
//takes in a grid to be able to set the width, height, and map with coordinates
//that are alive.
//Opens the user's file
//stores the first 2 lines into height and width
//sets the coordinates to true in the map
//returns the grid
grid fileReader::readFile(grid thisGrid, ifstream& myFile) {
  getline(myFile, line);
  cout << line << endl;
  thisGrid.height = stoi(line);
  getline(myFile, line);
  thisGrid.width = stoi(line);
  while(getline(myFile, line)) {
    j += 1;
    for(int i = 0; i < line.length(); ++i){
      if(toupper(line[i]) == 'X') {
        thisGrid.trueSlotsPrimary[make_pair(j,i)] = 3;
      }
    }
  }
  myFile.close();
  return thisGrid;
}


#endif
