#include <iostream>
#include <iomanip>

using namespace std;

#include "turn.h"

void Turn::display(){
  cout << fixed << right << endl;
  cout << "------------------- TURN -------------------\n\n";
  cout << setw(32) << "Community Cards: \n";
  cout << setw(19) << " ";
  for (int i=0; i < 3; i++){
    cout << community[i] << " ";
  }
}