#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "river.h"

 void River::display(){
   cout << fixed << right << endl;
  cout << "-------------------RIVER-------------------\n\n";
  cout << setw(32) << "Community Cards: \n";
  cout << setw(19) << " ";
  for (int i=0; i < 5; i++){
    cout << community[i] << " ";
  }
   cout << endl;
  cout << "Bank: $" << bank << "Pot: $" << pot;
  cout << setw(17) << "My Hand: " << convert(hand1[0]) << " ";
  cout << convert(hand1[1]) << "\n\n";
 }

int Cards::points(vector <int> hand[]){
  int points, x = 0, temp;
  
  int two = 0, trip = 0, quad = 0, penta = 0;
  
  int dCard1 = 0, dCard2 = 0, dCard3 = 0;
  int tCard1 = 0, tCard2 = 0;
  int qCard = 0, pCard = 0;
  
  bool isDiff = true, isStraight = true;

  vector <int> fullHand;
  
  for (int i = 0; i < 7; i++)
  {
    if (i<2)
      fullHand.pop_back(hand[x]);
    else 
      fullHand.pop_back(community[x-2]);
    ++x;
  }

  x = 0;

  for (int i = 0; i< 7; i++){
    if (fullHand[x] > fullHand[x + 1])
    {
      temp = fullHand[x];
      fullHand[x] = fullHand[x + 1];
      fullHand[x + 1] = temp;
    }
  }

  x = 0;

  for(int i = 1; i<6; i++){
    if (fullHand[i] == fullHand[i-1])
      isDiff = false;
  }

  if (isDiff == false)
  {
    x = 0;
    
    for(int i = 1; i<7; i++){
      //check if next card is the same
      if (fullHand[x] == fullHand[x + 1])
      {
        //check if the 4th card from current is the same
        if (fullHand[x] == fullHand[x + 4])
        {
          if (penta == 0) //there can only be one penta
          {
            pCard = fullHand.at(x);
            ++penta;
          }
        }
          //checks if third card from current is the same
        else if (fullHand[x] == fullHand[x + 3])
        {
          qCard = fullHand.at(x);
          ++quad;
        }
        //checks if second card from current is the same
        else if (fullHand[x] == fullHand[x + 2])
        {
          if (trip == 0)
            tCard1 = fullHand.at(x);
          else if (trip == 1)
            tCard2 = fullHand.at(x);
          ++trip;
        }
        else //only the next card is the same
        {
          if (two == 0)
            dCard1 = fullHand.at(x);
          else if (two == 1)
            dCard2 = fullHand.at(x);
          else if (two == 2)
            dCard3 = fullHand.at(x);
          ++two;
        }
      }
      ++x;
    }
  } 
  else 
  { //all the cards are different
    for (int i = 6; i > 2; i--)
    {
      if(fullHand.at(i) - 1 != fullHand[i - 1])
        isStraight = false;
    }
    if (isStraight)
    {
      if (fullHand.at(6) == 14)
        points = fullHand.at(6) * 10000000;
      else
        points = fullHand.at(6) * 1000;
    }
    else
      points = fullHand.at(6);
  }

  //point guidelines:
  /*
    multiplyers:
    double: x100
    straight: x1,000
    triple: x10,000
    quad: x1,000,000
    straight flush: x10,000,000
    penta: x100,000,000
  */
  
  if (penta == 1)
  {
    points = pCard * 100000000;
  }
  else if (quad == 1)
  {
    if (qCard != fullHand.at(6))
      points = (qCard *1000000 + fullHand.at(6));
    else
      points = (qCard * 1000000 + fullHand.at(2));
  }
  else if (trip == 2)
  {
    points = (tCard1 * 100) + (tCard2 * 10000);
  }
  else if (trip == 1 && two == 1)
  {
    points = (tCard1 * 10000) + (dCard1 * 100);
  }
  else if (two == 3)
  {
    points = (dCard3 + dCard2 + dCard1) * 100;
  }
  else if (two == 2)
  {
    if (dCard2 != fullHand[6])
      points = 100 * (dCard1 + dCard2) + fullHand[6];
    else if (dCard1 != fullHand[4])
      points = 100 * (dCard1 + dCard2) + fullHand[4];
    else
      points = 100 * (dCard1 + dCard2) + fullHand[2];
  }
  else if (two == 1)
  {
    if (dCard1 != fullHand[6])
      points = (dCard1 * 100) + fullHand[6];
    else
      points = (dCard1 * 100) + fullHand[4];
  }

  return points;
}

void Cards::winner(int p1, int p2){
  if (p1 > p2)
  {
    cout << "You win!";
    cout << "You got a " << hand(p1) << endl;
    bank += pot;
  }
  else if (p2 > p1)
  {
    cout << "The bot wins!";
    cout << "They got a " << hand(p2) << endl;
  }
  else
  {
    cout << "You tied! The pot is split\n";
    bank += pot/2;
  }
}