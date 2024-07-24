#include <iostream>
using namespace std;

#include "cards.h"
#include "flop.h"
#include "turn.h"
#include "river.h"

int main() {
  int round = 1, choice = 0;
  bool repeat = true;

  while (repeat) {
    while (round != 8){
      if (round == 1)
      {
        Cards a;
      }
      else if (a.run())
      {
        Flop b(a);
      
        if (b.run()){
          Turn c(b);
          
          if (c.run())
          {
            River d(c);

            if (d.run())
              Cards a(d.getBank());
          }
          else
          {
            Cards a(c.getBank());
          }
        }
        else 
        {
          Cards a(b.getBank());
        }
      }
      else
      {
        Cards a(a.getBank());
      }
      ++round;
    }
    while (choice != 1 && choice != 2){
      cout << "Play again? 1 for yes, 2 for no: ";
      cin >> choice;
    }
    if (choice == 2){
      repeat = false;
    }
  }

  cout << "Thank you for playing!";
}