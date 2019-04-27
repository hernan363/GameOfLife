#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"

fileReader::fileReader(){
  fileName = "";
  line = "";
}

fileReader::fileReader(string targetFile) {
  fileName = targetFile;
  line = "";
}

fileReader::~fileReader(){}
//Opens a file and creates the grid in the file into an array
grid fileReader::readFile(grid thisGrid) {
  // map<pair<int,int>,bool> falseItems;
  cout << fileName << "File Name" << endl;
  myFile.open(fileName.c_str()); //opening file

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
        thisGrid.trueSlots[make_pair(j,i)] = true;
      }
    }
  }

  myFile.close(); //closing file
  return thisGrid;
}


#endif
