//
//  QwintoRow.h
//  DiceGame
//
//  Created by Haider on 2017-11-23.
//  Copyright © 2017 Haider. All rights reserved.
//

#ifndef QwintoRow_h
#define QwintoRow_h
#include "Colour.h"
#include "RollOfDice.h"

template <Colour C> class QwintoRow {

public:
    int qwinRow[10]; //array for the row
    
    QwintoRow(){
        for (int i = 0; i < 10; i++)
            qwinRow[i] = 0;
    }
    
    inline int& operator[] (const int index){ return qwinRow[index]; } //overloading the conversion operator
    
    bool validate(RollOfDice rd, int index); //function to perform error checking
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& obj);
};
#endif /* QwintoRow_h */



