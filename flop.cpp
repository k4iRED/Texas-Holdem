#include <iostream>
#include <iomanip>
using namespace std;

#include "flop.h"

void Flop::display()
{
  cout << fixed << right << endl;
  cout << "------------------- FLOP -------------------\n\n";
  cout << setw(32) << "Community Cards: \n";
  cout << setw(19) << " ";
  for (int i=0; i < 3; i++)
    cout << community[i] << " ";
}

bool Flop::run(){
  
}