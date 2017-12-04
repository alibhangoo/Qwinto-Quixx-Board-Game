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
public:
    std::string playerName;
    int failedAttempts;
    int overallScore;
    
    ScoreSheet(const std::string& name = "");
    
    virtual ~ScoreSheet(); //base classes require virtual destructors
    
    bool score(RollOfDice rd, Colour colourSelected, int leftPosition = -1);
    virtual int calcTotal() = 0; //virtual function
    void setTotal();
    virtual bool const operator!(); //overloading not operator
    
    //overload insertion operator, behaves polymorphically
    friend std::ostream& operator<<(std::ostream& os, const ScoreSheet& obj);

    
protected:
    virtual bool validate(RollOfDice rd, Colour colourSelected, int leftPosition = -1) = 0; //score calls this function
    
};

#endif /* ScoreSheet_h */
