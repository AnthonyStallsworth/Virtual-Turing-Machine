#include "../include/TMComposition.h"

int main(int nargs, char **args)
{
  string equation = "2 + 2 + (2 * 2 + 2 - 2 + 2 * 2) - 2";
  TMComposition t(equation);
  t.makePrintable();
  cout << "The end result is: " << t.run() << endl;
}
