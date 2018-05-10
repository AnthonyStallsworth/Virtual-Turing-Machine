#include "../include/STT.h"
#include "../include/TM_OP_TABLES.h"

Transition createTrans(Bit write, Bit direction, int nextState)
{
  return Transition(nextState, write, direction);
}

State createState(vector<Transition> vt, bool isFinal)
{
  return State(vt, isFinal);
}

STT makeAdd()
{
  /* Transition Stuff */
  Bit write;
  Bit direction;
  int nextState;

  /* State Stuff */
  vector<Transition> vt(2);
  bool isFinal;

  /* STT Stuff */
  vector<State> vs;

  /* S0 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 1;
  vt[0] = createTrans(write, direction, nextState);
  isFinal = false;
  State s = createState(vt, isFinal);
  vs.push_back(s);

  /* S1 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 2;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 1;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S2 */
  write = Bit(1);
  direction = Bit(1);
  nextState = 3;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S3 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 4;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 6;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S4 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 5;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S5 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 5;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(0);
  nextState = 5;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = true;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S6 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 7;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 6;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S7 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 8;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S8 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 9;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S9 */
  write = Bit(1);
  direction = Bit(0);
  nextState = 10;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(0);
  nextState = 9;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S10 */  
  write = Bit(0);
  direction = Bit(0);
  nextState = 10;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(0);
  nextState = 10;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = true;
  s = createState(vt, isFinal);
  vs.push_back(s);

  STT state_trans_table(vs);
  return state_trans_table;  
}

STT makeSub()
{
  /* Transition Stuff */
  Bit write;
  Bit direction;
  int nextState;

  /* State Stuff */
  vector<Transition> vt(2);
  bool isFinal;

  /* STT Stuff */
  vector<State> vs;

  /* S0 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 1;
  vt[0] = createTrans(write, direction, nextState);
  isFinal = false;
  State s = createState(vt, isFinal);
  vs.push_back(s);

  /* S1 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 2;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 1;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S2 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 2;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 3;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S3 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 4;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 7;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S4 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 5;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S5 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 6;
  vt[0] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S6 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 6;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(0);
  nextState = 6;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = true;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S7 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 8;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(1);
  nextState = 7;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S8 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 9;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S9 */
  write = Bit(0);
  direction = Bit(0);
  nextState = 10;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(1);
  direction = Bit(0);
  nextState = 9;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S10 */  
  write = Bit(0);
  direction = Bit(0);
  nextState = 10;
  vt[0] = createTrans(write, direction, nextState);
  write = Bit(0);
  direction = Bit(1);
  nextState = 11;
  vt[1] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  /* S11 */
  write = Bit(0);
  direction = Bit(1);
  nextState = 2;
  vt[0] = createTrans(write, direction, nextState);
  isFinal = false;
  s = createState(vt, isFinal);
  vs.push_back(s);

  STT state_trans_table(vs);
  return state_trans_table;  
}
