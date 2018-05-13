#include "../include/TuringMachine.h"
#include <iostream>
#include <assert.h>

/* ------------------------Turing Machine----------------------------- */
TuringMachine::TuringMachine()
{ tape = new Tape(); }

TuringMachine::TuringMachine(STT state_trans_t)
{ stt = state_trans_t; tape = new Tape(); }

TuringMachine::TuringMachine(const TuringMachine& other)
{ *tape = other.getTape(); }

TuringMachine::~TuringMachine()
{ 
  delete tape; 
}

STT TuringMachine::getSTT() const
{ return stt; }

TuringMachine::Tape& TuringMachine::getTape() const
{ return *tape; }

void TuringMachine::printTape()
{ tape->printTape(); }

void TuringMachine::printSTT()
{ stt.print(); }

void TuringMachine::placeNum(int value, bool printIt)
{ 
  if(printIt)
    printTape();
  tape->placeNum(value, printIt); 
}

int TuringMachine::run(bool printIt)
{

  State curState = stt.getState(0);         /* Always start here! */
  Transition t = curState.getTransition(0); /* Starting Bit on Tape is always 0! */
  int readBit;

  while(!(curState.accepts() && tape->pos() == 0))
  {
    /* Use the transition on your Write */
    readBit = tape->write(t.getWriteBit(), t.getDirectionBit(), printIt);
    /* Set the current state */
    curState = stt.getState(t.getNextState());
    /* Set the Transition */
    t = curState.getTransition(readBit);
  }

  showOutput();
  return tape->getOutput();
}

void TuringMachine::showOutput()
{
  int result = tape->getOutput();

  std::cout << "The tape now holds the number: " << std::endl;
  std::cout << result << std::endl;
}

TuringMachine& TuringMachine::operator=(const TuringMachine& other)
{ stt = other.getSTT(); }

/* -------------------------------TAPE--------------------------------- */

TuringMachine::Tape::Tape()
{ theTape.push_back(Bit(0)); curPos = 0; }

TuringMachine::Tape::Tape(const Tape& other)
{ theTape = other.getTape(); curPos = other.pos(); }

int TuringMachine::Tape::write(Bit writeBit, Bit direction, bool printIt)
{

  if(direction == Bit(0))
  {
    theTape[curPos] = writeBit;
    curPos -= 1; /* Direction = Left */
  }

  if(direction == Bit(1))
  {
   if(curPos == theTape.size()-1)
     theTape.push_back(Bit(0));
     theTape[curPos] = writeBit;
     curPos += 1; /* Direction = Right */
  }
  
  if(printIt)
    printTape();

  return theTape[curPos].getBit();
}

/*
 * Should assert that the curPos (of the head)
 * is at the start. Places a number on the tape.
 */
void TuringMachine::Tape::placeNum(int startVal, bool printIt)
{ 
  assert(curPos == 0);
  write(Bit(0), Bit(1), printIt); /* write 0 and move right */
  startVal += 1;
  int startCopy = startVal;

  /* Go past all previous numbers */
  while(theTape[curPos] == Bit(1))
  {
    write(Bit(1), Bit(1), printIt);

    if(theTape[curPos] == Bit(0))
      write(Bit(0), Bit(1), printIt);
  }

  /* Write the value out */
  while(startVal > 0)
  {
    write(Bit(1), Bit(1), printIt);
    startVal -= 1;
  }

  write(Bit(0), Bit(0), printIt);

  /* Move back to the start of tape */
  while(curPos > 0)
  {
    if(theTape[curPos] == Bit(0))
    {
      write(Bit(0), Bit(0), printIt);
    } else {
      write(Bit(1), Bit(0), printIt);
    }
  }

  assert(curPos == 0);
}

int TuringMachine::Tape::getOutput()
{
  int output = -1;
  write(Bit(0), Bit(1), false); /* Write 0 and move right */

  /* Go through the number that is currently on the tape */
  while(theTape[curPos] == Bit(1))
  {
    write(Bit(1), Bit(1), false);
    output++;
  }

  write(Bit(0), Bit(0), false); /* Write 0 and move left */  

  /* Go back to the start of the tape */
  while(theTape[curPos] == Bit(1))
  {
    write(Bit(1), Bit(0), false);
  }
  return output;
}

vector<Bit> TuringMachine::Tape::getTape() const
{ return theTape; }

void TuringMachine::Tape::printTape()
{
  std::cout << "  START:" << std::endl;
  int pos = 0;

  for(Bit x : theTape)
  {
    int printVal = x.getBit();
    std::cout << "    |" << printVal << "|";
    if(pos == curPos)
    {
      std::cout << " <- head position" << std::endl;
    } else {
      std::cout << std::endl;
    }
    pos += 1;
  }

  std::cout << std::endl;
}

int TuringMachine::Tape::pos() const
{
  return curPos;
}

TuringMachine::Tape& TuringMachine::Tape::operator=(const Tape& other)
{ theTape = other.getTape(); curPos = other.pos(); return *this; }
