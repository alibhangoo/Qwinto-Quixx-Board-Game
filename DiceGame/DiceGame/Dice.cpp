//
//  Dice.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-20.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <stdio.h>
#include "Dice.h"

//defining static variables
std::random_device RandomDice::seed_generator;
std::mt19937 RandomDice::generator(seed_generator()); //seeding the generator


// --- Implementation of Dice Class Functions ---

//implementing constructor
Dice::Dice(Colour c):colour(c){}

//implementing roll
int Dice::roll(){
    std::uniform_int_distribution<> dis(1,6); //standard distribution b/w [1,6]
    return face = dis(RandomDice::generator);
}



