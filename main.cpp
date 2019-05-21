#include <iostream>
#include "prompt.h"

using namespace std;

int main(int argc, char const *argv[]){

  //execs the programs through the prompt file
  prompt c;
  c.firstPrompt();
  c.secondPrompt();
  c.thirdPrompt();

  return 0;
}
