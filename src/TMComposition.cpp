#include "../include/TMComposition.h"
#include <stack>

TMComposition::TMComposition(string expression)
{
  reader = Parser(expression);
  postfix = reader.infixToPostfix();
  print = false;
  curPos = 0;
}

void TMComposition::makePrintable()
{ print = true; }

string TMComposition::returnOp()
{
  string op;
  op = postfix[curPos++];

  if(postfix[curPos] == ' ')
    curPos++;

  return op;
}

int TMComposition::returnInt()
{
  int value = 0;
  string number;

  while(postfix[curPos] != ' ' && postfix[curPos] != '\0')
    number += postfix[curPos++];
  
  if(postfix[curPos] == ' ')
    curPos++;

  value = atoi(number.c_str());
  return value;
}

/* First pop equals lhs, Second pop equals rhs */
int TMComposition::run()
{
  /* Stack which holds the integers */
  stack<int> stack;

  /* Main Turing Machine */
  TuringMachine t;

  /* Addition and Subtraction Turing Machines */
  TuringMachine copyAdd(makeAdd());
  TuringMachine copySub(makeSub());

  /* Operator */
  string op;

  /* Return value */
  int retVal = 0;

  while(postfix[curPos] != '\0')
  {
    if(isdigit(postfix[curPos]))
    {
      /* Number */
      stack.push(returnInt());

    } else {
      /* Operator */
      op = returnOp();
      if(op == "+")
      {
        t = copyAdd;

        t.placeNum(stack.top(), print);
        stack.pop();
        t.placeNum(stack.top(), print);
        stack.pop();

        stack.push(t.run(print));
        t.clearTape();

      } else if(op == "-") {
      
        t = copySub;

        int lhs = stack.top();
        stack.pop();
        int rhs = stack.top();
        stack.pop();

        t.placeNum(rhs, print);
        t.placeNum(lhs, print);

        stack.push(t.run(print));
        t.clearTape();
      } else if(op == "*") {
        
        t = copyAdd;

        int lhs = stack.top();
        stack.pop();
        int rhs = stack.top();
        stack.pop();

        int placeholder = lhs;
        t.placeNum(lhs, print);

        while(rhs > 1)
        {
          t.placeNum(placeholder, print);
          lhs = t.run(print);
          rhs--;
        }

        stack.push(lhs);
        t.clearTape();

      }
    }
  }

  retVal = stack.top();
  stack.pop();

  return retVal;
}
