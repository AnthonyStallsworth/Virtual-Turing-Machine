#include "TuringMachine.h"

class Parser
{
  public:
   Parser(string equation);
   string parseInt();
   string parseOp();
   int getPrecedence(string op);
   string infixToPostfix();

  private:
   string equation;
   int curPos;
};
