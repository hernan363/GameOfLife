#ifndef PROMPT_CPP
#define PROMPT_CPP

#include "prompt.h"

using namespace std;
prompt::prompt() {
  fileName = "";

}

prompt::~prompt(){}

void firstPrompt(string fileName) {
  cout << "Please provide a file that can run the simulation: " << endl;
  cin >> fileName;


  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

}

#endif
