#include "../include/Parser.h"

int main(int nargs, char **args)
{
  string equation = "2 + ((2 * 2) + 1) + 1";
  Parser p(equation);
  cout << p.infixToPostfix() << endl;
}
