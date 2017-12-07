//
//  RollOfDice.cpp
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#include "RollOfDice.h"

// --- Implementation of RollOfDice Class Functions ---


//construtor
RollOfDice::RollOfDice(std::vector<Dice> vD) : vDice(vD){}

//function roll, rolls all the dice in the container
void RollOfDice::roll(){
    for(Dice &d: vDice){ //loop through dice
        d.roll();
    }
}

//function pair returns a RollOfDice with two selected Dice in it
RollOfDice RollOfDice::pair(const Dice& one, const Dice& two){
    std::vector<Dice> tmp = {one, two}; //create a new vector and add the two dice in it
    return RollOfDice(tmp);
}

//function to overload the implicit conversion from RollOfDice to Integer
RollOfDice::operator int() const{
    int total = 0;
    for(Dice d: vDice){
        total += d.face;
    }
    return total;
}

//function to overload insertion operator to an output stream
std::ostream& operator<<(std::ostream& os, const RollOfDice& rd){
    int counter = 1;
    os << "Roll Of Dice: " << std::endl;

    for(Dice d: rd.vDice){
        os << d;
        counter++;
    }
    os<<"Total: " << int(rd) <<std::endl;
    return os;
}

