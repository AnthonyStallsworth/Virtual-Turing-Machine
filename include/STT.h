#include "State.h"

class STT
{
 public:
  STT();                           /* Default Constructor */
  STT(vector<State> stt);          /* create the STT from a vector of states */
  State getState(int curState);    /* return a state at position curState */
  void pushState(State s);         /* Push a State onto the vector of states */
  vector<State> getTable();        /* Return a copy of the table */
  int size();                      /* Get the length of the table */
  void print();                    /* Print the STT */
 
 private:
  vector<State> state_trans_table; /* The table */
};
