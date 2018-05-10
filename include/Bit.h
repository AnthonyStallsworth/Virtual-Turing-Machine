/*******************************************************
* This is probably the dumbest class I have ever made  *
* The only reason it exists is because I would like to *
* enforce an integer to only 0 or 1. I am not sure     *
* how to do this without making a wrapper class.       *
* I guess I could have just used a boolean!            *
* There really is not a need for a destructor yet.     *
*******************************************************/
#include <assert.h>
#include <string>
#include <iostream>

class Bit
{
 public:
  Bit();                     /* Sets the bit to 0 */
  Bit(int x);                /* Set the bit while constructing it. Enforces 0 or 1. */
  int getBit();              /* Returns the bit, could be used as a boolean */
  bool operator==(Bit rhs);  /* Overloading the == operator */
  void print();              /* Print the bit */

 private:
  int theBit;                /* the bit */
};
