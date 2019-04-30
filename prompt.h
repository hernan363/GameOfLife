#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include "fileReader.h"
#include "classic.h"

using namespace std;

class prompt {
  private:
    fileReader newGrid;
    string fileName;
    void firstPrompt();

  public:
    classic c1;
    grid g1;

    prompt();
    ~prompt();


};
#endif
