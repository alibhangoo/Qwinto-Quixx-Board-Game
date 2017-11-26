//
//  main.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-20.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <iostream>
#include <random>
#include "Dice.h"
#include "RollOfDice.h"

using namespace std;

int main() {
    
    Colour b = Colour::RED;
    Dice c(b);
    Dice d(b);
    std::vector<Dice>dV = { c,d };
    
    RollOfDice z(dV);
    int awignahan;
    for (int i = 0; i < 500; i++) {
        z.roll();
        awignahan = z;
        std::cout << z;
        std::cout << "Sum of dice in rollDice: " << awignahan << endl;
    }
    
    
    return 0;
    
}

