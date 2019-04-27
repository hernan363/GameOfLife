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
  g1.fillGridWithTrue();
  g1.printAll();

}

#endif
