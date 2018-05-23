#include "Parser.h"
#include "TM_OP_TABLES.h"

class TMComposition
{
  public:
   TMComposition(string expression);
   void makePrintable();
   string returnOp();
   int returnInt();
   int run();

  private:
   Parser reader;
   string postfix;
   bool print;
   int curPos;
};
