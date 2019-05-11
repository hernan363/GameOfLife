#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <fstream>

#include "fileReader.h"
#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

using namespace std;

class prompt {
  private:
    string fileName;
    string answer;
    char mode;

    fileReader newGrid;
    fileReader fr;

    void readFilePrompt();
    void simulationWithPauses(int counter);
    int heightAndWidth(string s, int value);


    void returnMapDeterminedByMode();

    string toLower(string s);
    void determineMode();
    void generateLife(float value);
    void output(int counter);
    string outputFileToString(string tempString);
    ifstream targetFileInput;
    ofstream targetFileOutput;

    classic c1;
    grid g1;
    doughnut d1;
    mirror m1;

  public:
    void firstPrompt();
    void secondPrompt();
    void thirdPrompt();

    prompt();
    ~prompt();

};
#endif
