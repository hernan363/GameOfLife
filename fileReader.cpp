#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"

fileReader::fileReader(){
  fileName = "";
  line = "";
}

fileReader::fileReader(string targetFile) {
  // myFile = targetFile;
  line = "";
}

fileReader::~fileReader(){}
//Opens a file and creates the grid in the file into an array
grid fileReader::readFile(grid thisGrid, ifstream& myFile) {
  //height
  getline(myFile, line);
  cout << line << endl;
  thisGrid.height = stoi(line);


  //width
  getline(myFile, line);
  thisGrid.width = stoi(line);

  int j = -1;
  //O(N*M) where N is the number of lines and M is the length of the Line
  while(getline(myFile, line)) {
    j += 1;
    for(int i = 0; i < line.length(); ++i){
      if(toupper(line[i]) == 'X') {
        thisGrid.trueSlotsPrimary[make_pair(j,i)] = 3;
      }
    }
  }

  myFile.close(); //closing file
  return thisGrid;
}


#endif
