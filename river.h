#ifndef RIVER_H
#define RIVER_H

#include <iostream>
#include <vector>
using namespace std;

#include "turn.h"

class River: Turn {
public:
River(){}


void display();
int getPot();
int getBank();
bool run(const Cards &a);
int points(vector <int> hand);

};
#endif