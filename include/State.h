#include "Transition.h"
#include <vector>
using namespace std;

class State
{
 public:
  State();                             /* Default Constructor */
  State(vector<Transition> s, bool f); /* Construct the state from a vector of Transitions */
  Transition getTransition(int cur);   /* Returns the transition that you specify */
  bool accepts();                      /* Returns if this state is an accepting state or not */
  void print();                        /* Print the state */

 private:
  vector<Transition> state;            /* The state */
  bool isFinal;                        /* Is this state accepting or not */
};
