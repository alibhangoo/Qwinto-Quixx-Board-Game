//
//  Player.h
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#ifndef Player_h
#define Player_h
#include "RollOfDice.h"

class Player{
public:
    bool activePlayer; //check to see if this is the active player
    virtual void inputBeforeRoll(RollOfDice& rd) = 0;
    virtual void inputAfterRoll(RollOfDice& rd) = 0;
};

#endif /* Player_h */
