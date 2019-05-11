#ifndef PROMPT_CPP
#define PROMPT_CPP

#include "prompt.h"
#include "fileReader.h"
#include "grid.h"

using namespace std;
prompt::prompt() {
  fileName = "";
  grid g1;
  answer = "";
  mode = ' ';

  // firstPrompt();
}

prompt::~prompt(){}

string prompt::toLower(string s) {
  for(int i = 0; i < s.length(); ++i) {
    s[i] = tolower(s[i]);
  }
  return s;
}
///////////////////////PROMPTS///////////////////////////////////
void prompt::firstPrompt() {
  do {
    cout << "Would you like to simulate the Game of Life through a file?" << endl;
    cout << "(Options: 'yes' or 'no')" << endl;
    cout << "(No will force the system to randomly generate life)" << endl;
    cout << endl;
    cin >> answer;
  } while ( toLower(answer) != "yes" && toLower(answer) != "no");

  if(answer == "yes") {
    readFilePrompt();
  }
  else {
    generateLife(0);
  }
}

void prompt::secondPrompt() {
  do{
    cout << "What mode would you like to run in?" << endl;
    cout << "Options: 'classic', 'doughnut', or 'mirror'" << endl;
    cout << endl;
    cin >> answer;
    toLower(answer);
  } while (answer != "classic" && answer != "doughnut" &&
           answer != "mirror");
  mode = answer[0];
}

void prompt::thirdPrompt() {
  do {
    cout << "Would you like a live display of the game?" << endl;
    cout << "(Options: 'yes' or 'no')" << endl;
    cout << "(No leads to outputting the game to ";
    cout << "a file that you would name)" << endl;
    cout << endl;
    cin >> answer;
    toLower(answer);
  } while(answer != "yes" && answer != "no");

  if(answer == "yes") {
    simulationWithPauses(0);
  }
  else {
    output(0);
  }
}

//////////////////GENERATE FILE/////////////////////////////
void prompt::readFilePrompt() {

  //Sanitizes the User's file input
  do {
    cout << "Please name a file that can run the simulation: " << endl;
    cout << "(The text files I provided are: 'glider.txt' and 'gg.txt')" << endl;
    cout << endl;
    cin >> fileName;
    targetFileInput.open(fileName.c_str());
  } while (! targetFileInput.good());

  //reads the file and inserts the living indexes to
  //the hash map
  g1 = fr.readFile(g1, targetFileInput);
  //initializes both the primary and secondary grids to
  //all 0's
  g1.setGridsToFalse();
  //fills the primary grid with the living indexes
  //from the hash map
  g1.mapToGrid();

  targetFileInput.close();  //closes file
}

///////////////////////Generate LIFE/////////////////////////////////////

void prompt::generateLife(float value) {
  do {
    cout << "What percent of life do you want to create?" << endl;
    cout << "(Options: a decimal value within the range (0 < X <= 1) )" << endl;
    cout << endl;
    cin >> answer;
    value = stof(answer);
  } while (value < 0 || value > 1);
  g1.popPercent = value*100;
  g1.height = heightAndWidth("height",0);
  g1.width = heightAndWidth("width",0);

  g1.setGridsToFalse();
  g1.randomGenerateMap();
}

int prompt::heightAndWidth(string s,int value) {
  do {
    cout << "What is the " << s << " of the grid you want to generate?" << endl;
    cout << "(Options: any number you want that is below 1000)" << endl;
    cout << endl;
    cin >> answer;
    value = stoi(answer);
  }while(value < 0 || value > 1000);

  return value;
}

///////////////////////OUTPUT TO A FILE///////////////////////////////////////

void prompt::output(int counter) {
  cout << "What is the name of the file you want to outputting to?" << endl;
  cout << endl;
  cin >> answer;
  answer.append(".txt");
  targetFileOutput.open(answer.c_str());
  targetFileOutput << outputFileToString("");
  while(!(g1.compareGrids()) && counter != 1000) {
    targetFileOutput << "\n";
    targetFileOutput << "\n";

    g1.setGridSecondary();
    returnMapDeterminedByMode();
    g1.mapToGrid();
    targetFileOutput << outputFileToString("");
    ++counter;
  }
  targetFileOutput.close();
}

string prompt::outputFileToString(string tempString) {
  for(int i = 0; i < g1.height; ++i) {
    for(int j = 0; j < g1.width; ++j) {
      if(g1.gridPrimary[i][j] == false) {
        tempString.append("-");
      }
      else {
        tempString.append("X");
      }
    }
    tempString.append("\n");
  }
  return tempString;
}
/////////////////////////SIMULATIONS////////////////////////////////////////////
void prompt::returnMapDeterminedByMode() {
  switch (mode) {
    case 'c':
      g1.trueSlotsPrimary = c1.classicNeighborCount(g1);
      break;

    case 'd':
      g1.trueSlotsPrimary = d1.doughnutNeighborCount(g1);
      break;

    case 'm':
      g1.trueSlotsPrimary = m1.mirrorNeighborCount(g1);
      break;

  }
}

void prompt::simulationWithPauses(int counter) {
  while(!(g1.compareGrids()) && counter != 1000) {
    getchar();
    g1.setGridSecondary();
    returnMapDeterminedByMode();
    g1.mapToGrid();
    g1.printAll();
    ++counter;
  }
}



#endif
