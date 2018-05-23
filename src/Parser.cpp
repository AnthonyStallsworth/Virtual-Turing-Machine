#include "../include/Parser.h"
#include "../include/TM_OP_TABLES.h"
#include <string>
#include <stack>
#include <queue>
#include <ctype.h>

Parser::Parser(string equat)
{
  equation = equat;
  curPos = 0;
}

/* Get the current integer in the equation */
string Parser::parseInt()
{
  string number = "";

  while(isdigit(equation[curPos]) && equation[curPos] != '\0')
  {
    number += equation[curPos];
    curPos++;
  }

  if(equation[curPos] == ' ')
    curPos++;

  //return atoi(number.c_str());
  return number;
}

/* Parse an operator from the equation */
string Parser::parseOp()
{
  string op;
  op = equation[curPos++];
  if(equation[curPos] == ' ')
    curPos++;

  return op;
}

/* Get the precedence of the current operator */
int Parser::getPrecedence(string op)
{
  if(op == "(") return 0;
  if(op == "+" || op == "-") return 1;
  if(op == "*" || op == "/") return 2;
  if(op == "^") return 3;
  if(op == ")") return 4;
  throw runtime_error("Expression '" + op + "' is not part of the language.");
}

/* Convert the infix notation to a postfix notation algorithm */
string Parser::infixToPostfix()
{
  string postfix;
  string op;

  /* Operator stack and output queue */
  stack<string> op_stack;
  queue<string> out;
  
  /* Start the old precedence at a low value for the first comparison */
  int old_precedence = -1;
  int new_precedence = 0;

  bool wasTrue = false;

  /* Infix to Postfix */
  while(equation[curPos] != '\0')
  {
    if(isdigit(equation[curPos]))
    {

      /* We need to push the integer into the output queue */
      out.push(parseInt());

    } else {

      /* Calculate new precedence */
      op = parseOp();
      new_precedence = getPrecedence(op);
 
      /* View previous precedence */
      if(op_stack.size() > 0)
      {
        old_precedence = getPrecedence(op_stack.top());
      } else {      
        old_precedence = -1;
      }

      /* Compare */
      if(new_precedence > 0 && new_precedence < 4)
      {
        while(old_precedence >= new_precedence && op_stack.size() > 0)
        {
          /* Pop the old operator into the output queue */
          out.push(op_stack.top());
          op_stack.pop();
          if(op_stack.size() > 0)
          {
            old_precedence = getPrecedence(op_stack.top());
          } else {
    	    old_precedence = -1;
          }
        }

        op_stack.push(op);
        old_precedence = new_precedence;
      }

      if(new_precedence == 4)
      {
        /* Do something here! */
        while(old_precedence != 0)
        {
          out.push(op_stack.top());
          op_stack.pop();
          old_precedence = getPrecedence(op_stack.top());
        }

        op_stack.pop();
        old_precedence = new_precedence;
      }

      if(new_precedence == 0)
      {
        op_stack.push(op);
        old_precedence = new_precedence;
      }
    }
  }
  
  /* Pop the stack into the output queue */
  while(op_stack.size() > 0)
  {
    out.push(op_stack.top());
    op_stack.pop();
  }

  /* Create the postfix expression from the output queue */
  while(out.size() > 0)
  {
    postfix += out.front();
    out.pop();
  }

  return postfix;
}
