//
//  RollOfDice.h
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#ifndef RollOfDice_h
#define RollOfDice_h
#include "Dice.h"
#include <vector>

struct RollOfDice { //container structure that holds multiple dice as in a roll
    std::vector<Dice> vDice;
    
    RollOfDice(){};
    RollOfDice(std::vector<Dice> vD);
    void roll();
    RollOfDice pair(const Dice&, const Dice&);
    operator int() const;
    friend std::ostream& operator<<(std::ostream& os, const RollOfDice& rd);
};

#endif /* RollOfDice_h */
