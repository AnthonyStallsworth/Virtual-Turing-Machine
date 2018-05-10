#include "../include/State.h"

/**************************************************
* The default constructor should fill the 1 space *
* with a default Transition object. This object   *
* Should always just move left and place 0 on     *
* the tape. Again, it is up to the programmer to  *
* do the rest of the work.                        *
**************************************************/

State::State()
{
  state.resize(1);
}

State::State(vector<Transition> s, bool fin)
{
  state = s;
  isFinal = fin;
}

Transition State::getTransition(int cur)
{
  return state[cur];
}

bool State::accepts()
{
  return isFinal;
}

void State::print()
{
  std::cout << "If I read 0 on the tape: " << std::endl;
  state[0].print();
  std::cout << std::endl;

  std::cout << "If I read 1 on the tape: " << std::endl;
  state[1].print();
  std::cout << std::endl;
}
