//
//  ScoreSheet.cpp
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#include <stdio.h>
#include "ScoreSheet.h"


// --- Implementation of ScoreSheet Class Functions ---

//implementing constructor
ScoreSheet::ScoreSheet(const std::string& name) {
    playerName = name;
    overallScore = 0;
    failedAttempts = 0;
}

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


