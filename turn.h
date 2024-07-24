#ifndef TURN_H
#define TURN_H

#include <iostream>
using namespace std;

#include "flop.h"

class Turn: Flop {
public:
Turn(){}

void display();
bool run();
};

#endif 