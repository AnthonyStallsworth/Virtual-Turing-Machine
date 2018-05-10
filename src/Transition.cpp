#include "../include/Transition.h"

/****************************************************
* Default direction will go left from default       *
* This should end since it goes off the tape.       *
* There should ONLY be values set AT CONSTRUCTION   *
* This is so that no transitions get changed during *
* runtime.                                          *
* The Getter functions should return a copy of the  *
* values that way someone cannot change them        *
* halfway through. The goal here is to avoid        *
* data destruction during runtime.                  *
* I can stress-test later on to see if I can change *
* values during runtime.                            *
****************************************************/

Transition::Transition()
{
  nextState = 0;
  write = Bit(0);
  direction = Bit(0);
}

Transition::~Transition()
{
  nextState = 0;
  /* Destructor should automatically call delete on Object members */
}

Transition::Transition(int ns, Bit w, Bit d)
{
  nextState = ns;
  write = w;
  direction = d;
}

int Transition::getNextState()
{
  int x = nextState;
  return x;
}

Bit Transition::getWriteBit()
{
  Bit x = write;
  return x;
}

Bit Transition::getDirectionBit()
{
  Bit x = direction;
  return x;
}

void Transition::print()
{
  assert(direction == Bit(0) || direction == Bit(1));

  std::string dir;

  if(direction == Bit(0))
  {
    dir = "Left";
  } else {
    dir = "Right";
  }
  std::cout << "    Transition" << std::endl;
  std::cout << "        Write: ";
  write.print();
  std::cout << "        Direction: " << dir << std::endl;
  std::cout << "        Next State: " << nextState;
}
