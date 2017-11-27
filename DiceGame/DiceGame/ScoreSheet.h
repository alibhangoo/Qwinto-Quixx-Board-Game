//
//  ScoreSheet.h
//  DiceGame
//
//  Created by Haider on 2017-11-25.
//  Copyright © 2017 Haider. All rights reserved.
//

#ifndef ScoreSheet_h
#define ScoreSheet_h
#include <string>
#include "Colour.h"
#include "RollOfDice.h"

class ScoreSheet{
protected:
    virtual bool validate(RollOfDice rd, Colour c, int leftPosition = -1) = 0;
    
public:
    std::string playerName;
    int failedAttempts;
    int overallScore;
    
    ScoreSheet(const std::string& _firstName = "",
               const std::string& _lastName = "");
    
    bool score(RollOfDice rd, Colour c, int leftPosition = -1);
    virtual int calcTotal() = 0; //virtual function
    void setTotal();
    virtual bool const operator! (); //overloading not operator
    
    
};

#endif /* ScoreSheet_h */
