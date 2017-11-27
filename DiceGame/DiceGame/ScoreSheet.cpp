//
//  ScoreSheet.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-26.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <stdio.h>
#include "ScoreSheet.h"


// --- Implementation of ScoreSheet Class Functions ---

//implementing constructor
ScoreSheet::ScoreSheet(const std::string& _firstName,
                       const std::string& _lastName) : playerName(_firstName + " " + _lastName){}

//implementing the score function

bool score(RollOfDice rd, Colour c, int leftPosition = -1){
    return 1;
}
