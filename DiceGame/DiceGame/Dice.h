//
//  Dice.h
//  DiceGame
//
//  Created by Haider on 2017-11-20.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <random>
#ifndef Dice_h
#define Dice_h
#include "Colour.h"

struct RandomDice { //helper struct with only static objects
    static std::random_device seed_generator; //seed for random number engine
    static std::mt19937 generator; //mersene twister engine
};


struct Dice{
    const Colour colour;
    int face;
    
    Dice(Colour c); //constructor
    friend std::ostream& operator<<(std::ostream& out, const Dice& obj); //overloading operator
    int roll(); //change the face of dice every time roll is called
};

#endif /* Dice_h */
