#include "../include/Bit.h"

Bit::Bit()
{
  theBit = 0;
}

Bit::Bit(int x)
{
  if(x == 0 || x == 1)
      theBit = x;
}

int Bit::getBit()
{
  return theBit;
}

void Bit::print()
{
  std::cout << theBit << std::endl;
}

bool Bit::operator==(Bit rhs)
{
  return (theBit == rhs.getBit());
}
