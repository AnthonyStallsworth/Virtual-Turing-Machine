#include "Bit.h"

class Transition
{
 public:
  Transition();                     /* Default Constructor */
  ~Transition();                    /* Destructor */
  Transition(int ns, Bit w, Bit d); /* Constructor which is set through given input */
  
  int getNextState();               /* Get the next state */
  Bit getWriteBit();                /* Get the next Bit which you write to the tape */
  Bit getDirectionBit();            /* Get the next direction you go in */
  void print();                     /* Print the transition out */

 private:
  int nextState;                    /* The next state you go in after this transition */
  Bit write;                        /* The Bit you write before you transition */
  Bit direction;                    /* The direction you go in on the tape */
};
