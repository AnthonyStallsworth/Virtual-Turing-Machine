#include "TuringMachine.h"

class Parser
{
  public:
   Parser(string equat, bool isPrint);
   int parseInt();
   int getResult();

  private:
   string equation;
   int curPos;
   bool print;
};
