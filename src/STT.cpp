#include "../include/STT.h"

/************************************************
* The default constructor should create default *
* State values. We will keep adding them by     *
* calling pushState OR creating it all at once  *
* by calling the constructor which takes a      *
* vector of states.                             *
************************************************/

STT::STT()
{ state_trans_table.resize(1); }

STT::STT(vector<State> stt)
{ state_trans_table = stt; }

State STT::getState(int curState)
{ return state_trans_table[curState]; }

void STT::pushState(State s)
{ state_trans_table.push_back(s); }

vector<State> STT::getTable()
{ 
  vector<State> stt = state_trans_table;
  return stt;
}

int STT::size()
{ return state_trans_table.size(); }

void STT::print()
{
  int iter = -1;
  while(++iter != size())
  {
    std::cout << "The iter is at: " << iter << endl;
    state_trans_table[iter].print();
  }
}
