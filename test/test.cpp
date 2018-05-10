#include "../include/Parser.h"

int main(int nargs, char **args)
{
  bool print = true;
  string equation = "1 + 1 * 3 + 4 * 2";
  Parser p(equation, print);
  p.getResult();
}
