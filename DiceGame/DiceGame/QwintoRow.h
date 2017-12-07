//
//  QwintoRow.h
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#ifndef QwintoRow_h
#define QwintoRow_h
#include "Colour.h"
#include "RollOfDice.h"
#include<iostream>

template <Colour C> class QwintoRow {

public:
    int qwinRow[10]; //array for the row
    
    QwintoRow(){ //initialize the array to all 0's
        for (int i = 0; i < 10; i++)
            qwinRow[i] = 0;
    }
    
    inline int& operator[] (const int index){ return qwinRow[index]; } //overloading the conversion operator
    
    //implementation of validate inside header because it is a template (recommended by professor)
    bool validate(RollOfDice rd, int index) {
        int invalidIndex; //index with XX, which you cannot use
        
        switch(C){
            case Colour::RED:
                invalidIndex=3; break;
            case Colour::BLUE:
                invalidIndex=4; break;
            case Colour::YELLOW:
                invalidIndex=5; break;
            default:
                std::cout << "Dice must be Red, Blue or Yellow!" << std::endl;
                break;
        }
        
        
        if (index < 0 || index >= 10 || index == invalidIndex) return false; //cannot be out of array or placed at illegal spot (index 3, 4 or 5 depending on the colour)
        
        for (int i = 0; i < index; i++) { //check indexes to the left of where user wants to enter and ensure they are smaller
            if(i != invalidIndex){
                if((qwinRow[i] != 0) && (qwinRow[i] >= rd)) return false;
            }
        }
        
        for(int i = 9; i > index; i--){ //check indexes to the right of where user wants to enter and ensure they are larger
            if(i !=invalidIndex){
                if((qwinRow[i] != 0) && (qwinRow[i] <= rd)) return false;
            }
        }
        
        return qwinRow[index] == 0; //return true if the index we want to add to is empty
    }
    
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& obj);//overloading operator
};
#endif /* QwintoRow_h */



