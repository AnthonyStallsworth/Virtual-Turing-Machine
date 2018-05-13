#include "STT.h"

class TuringMachine
{

 class Tape;

 public:
  TuringMachine();
  TuringMachine(STT state_trans_t);
  TuringMachine(const TuringMachine& other);
  ~TuringMachine();
  STT getSTT() const;
  Tape& getTape() const;
  void printTape();
  void printSTT();
  void placeNum(int num, bool printIt);
  int run(bool printIt);
  void showOutput();
  TuringMachine& operator=(const TuringMachine& other);
  
 private:
  class Tape
  {
   public:
    Tape();
    Tape(const Tape& other);
    int write(Bit writeBit, Bit direction, bool printIt);
    void placeNum(int startVal, bool printIt);
    int getOutput();
    vector<Bit> getTape() const;
    void printTape();
    int pos() const;
    Tape& operator=(const Tape& other);

   private:
    vector<Bit> theTape;
    int curPos;

    friend class TuringMachine;
  };

  STT stt;
  Tape *tape;
};
