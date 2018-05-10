#include "STT.h"

class TuringMachine
{
 public:
  TuringMachine();
  TuringMachine(STT state_trans_t);
  STT getSTT();
  void printTape();
  void printSTT();
  void placeNum(int num, bool printIt);
  int run(bool printIt);
  void showOutput();
  
 private:
  class Tape
  {
   public:
    Tape();
    int write(Bit writeBit, Bit direction, bool printIt);
    void placeNum(int startVal, bool printIt);
    int getOutput();
    void printTape();
    int pos();

   private:
    vector<Bit> theTape;
    int curPos;

    friend class TuringMachine;
  };

  STT stt;
  Tape *tape;
};
