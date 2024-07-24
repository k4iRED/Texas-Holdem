#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <vector>
using namespace std;

class Cards {
protected:
vector <int> community, hand1, hand2;
int pot, bank;


public:
Cards(){
  for (int i=0; i <5; i++){
    community[i] = (rand()%13) + 2;
  }

  for (int i=0; i< 2; i++){
    hand1[i] = (rand()%13) + 2;
    hand2[i-1]= (rand()%13) + 2;
  }
  
  pot = 0;
  bank = 500;
}

Cards(int bank){
  for (int i=0; i <5; i++){
    community[i] = (rand()%13) + 2;
  }

  for (int i=0; i< 2; i++){
    hand1[i] = (rand()%13) + 2;
    hand2[i-1]= (rand()%13) + 2;
  }
  pot = 0;
  this -> bank = bank;
}

char convert(int num);

int getBank();

int points(vector <int> hand);

string hand(int points);

void winner(int p1, int p2);
};

#endif