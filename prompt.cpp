#ifndef PROMPT_CPP
#define PROMPT_CPP

#include "prompt.h"
#include "fileReader.h"
#include "grid.h"

using namespace std;
prompt::prompt() {
  fileName = "";
  grid g1;

  firstPrompt();
}

prompt::~prompt(){}

void prompt::firstPrompt() {

  cout << "Please provide a file that can run the simulation: " << endl;
  cin >> fileName;

  fileReader fr(fileName);

  g1 = fr.readFile(g1);
  g1.setGridsToFalse();
  g1.mapToGrid();
  g1.printAll();

  for(int i = 0; i  < 10; ++ i) {
    g1.trueSlotsPrimary = c1.classicNeighborCount(g1);
    g1.mapToGrid();
    g1.printAll();
  }


}

#endif
