#include "../include/Parser.h"
#include "../include/TM_OP_TABLES.h"
#include <string>

Parser::Parser(string equat, bool isPrint)
{
  equation = equat;
  curPos = 0;
  print = isPrint;
}

/* Get the current integer in the equation */
int Parser::parseInt()
{
  string number = "";

  while(equation[curPos] != ' ' && equation[curPos] != '\0')
  {
    number += equation[curPos];
    curPos++;
  }

  if(equation[curPos] == ' ')
    curPos++;

  return atoi(number.c_str());
}

int Parser::getResult()
{
  int rhs = 0;
  char op;
  TuringMachine t;
  TuringMachine copyAdd(makeAdd());
  TuringMachine copySub(makeSub());

  int lhs = parseInt();
  t.placeNum(lhs, print);
  copyAdd.placeNum(lhs, false);
  copySub.placeNum(lhs, false);

  while(equation[curPos] != '\0')
  {
    op = equation[curPos];
    curPos++;
    curPos++;
    rhs = parseInt();

    if(op == '+')
    {

      t = copyAdd;
      t.placeNum(rhs, print);

      lhs = t.run(print);

    } else if(op == '-') {

      t = copySub;

      t.placeNum(rhs, print);
      lhs = t.run(print);

    } else if(op == '*') {
      if(rhs > 1)
      { 
        t = copyAdd;
        int holder = lhs;
        while(rhs > 1)
        {
          t.placeNum(holder, print);
          lhs = t.run(print);
          rhs--;
        }
      }
    } else if(op == '/') {
        
      t = copySub;
 
      int counter = 0;
      while(lhs > rhs)
      {
        t.placeNum(rhs, print);
        lhs = t.run(print);
        counter++;
      }

      lhs = counter;
    }
  }
  std::cout << "The number at the end of the tape is: " << lhs << std::endl;
  return lhs;
}
