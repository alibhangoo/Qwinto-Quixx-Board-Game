//
//  Player.h
//  DiceGame
//
//  Created by Haider on 2017-11-26.
//  Copyright © 2017 Haider. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "RollOfDice.h"

class PLayer{
    bool activePlayer; //check to see if this is the active player
    virtual void inputBeforeRoll(RollOfDice& rd);
    virtual void inputAfterRoll(RollOfDice& rd);
};

#endif /* Player_h */
