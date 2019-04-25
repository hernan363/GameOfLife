#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include "fileReader.h"

using namespace std;

class prompt {
  private:
    fileReader newGrid;
    string fileName;
    void firstPrompt(string fileName);

  public:
    prompt();
    ~prompt();

};
#endif
