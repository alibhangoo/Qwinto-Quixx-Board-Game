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
ScoreSheet::ScoreSheet(const std::string& name) : playerName(name){}

//implementing the score function
bool ScoreSheet::score(RollOfDice rd, Colour colourSelected, int leftPosition){
    return validate(rd, colourSelected, leftPosition); //score calls validate to check if it's legal or not, returns bool
}

//implementing setTotal function
void ScoreSheet::setTotal(){
    overallScore = calcTotal();
}

//implementing not operator
bool const ScoreSheet::operator!(){
    return NULL;
}
//implementing the destructor
ScoreSheet::~ScoreSheet(){}


