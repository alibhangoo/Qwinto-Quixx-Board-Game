//
//  QwintoRow.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-23.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <stdio.h>
#include "QwintoRow.h"
#include "Colour.h"
#include <iostream>

// --- Implementation of QwintoRow Class Functions ---

//implementing validate for red row
template<Colour colour>
bool QwintoRow<colour>::validate(RollOfDice rd, int index) {
    int invalidIndex; //index with XX, which you cannot use
    
    switch(colour){
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
            if(qwinRow[i] > rd) return false;
        }
    }
    
    for(int i = 9; i > index; i--){ //check indexes to the right of where user wants to enter and ensure they are larger
        if(i !=invalidIndex){
            if((qwinRow[i] != 0) && (qwinRow[i] < rd)) return false;
        }
    }
    
    return qwinRow[index] == 0; //return true if the index we want to add to is empty
}

//implementing the insertion operator to print the QwintoRow to an output stream
std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::RED>& row){
    os << "Blue" << "         ";
    
    for(int i = 0; i<11; i++){
        switch(i){
            case 2:
                os << "%"; break;
            case 3:
                os << "%"; break;
            case 4:
                os << "|X"; break;
            case 9:
                os << "%"; break;
            case 10:
                os << "%"; break;
            default:
                os << "|"; break;
        }
        
        //check if double int (ex. 10), single int (ex. 8), or empty space
        if (i!=4 && i!=10){
            if(row.qwinRow[i] < 10 && row.qwinRow[i] != 0){
                os << " " << row.qwinRow[i];
            }else if(row.qwinRow[i] > 9){
                os << row.qwinRow[i];
            }else
                os << "  ";
        }
    }
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::YELLOW>& row){
    os << "Yellow" << "         ";
    
    for(int i = 0; i<11; i++){
        switch(i){
            case 5:
                os << "|XX"; break;
            case 7:
                os << "%"; break;
            case 8:
                os << "%"; break;
            default:
                os <<"|"; break;
        }
        
        //check if double int (ex. 10), single int (ex. 8), or empty space
        if (i!=3 && i!=10){
            if(row.qwinRow[i] < 10 && row.qwinRow[i] != 0){
                os << " " << row.qwinRow[i];
            }else if(row.qwinRow[i] > 9){
                os << row.qwinRow[i];
            }else
                os << "  ";
        }
    }
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::BLUE>& row){
    os << "Red" << "         ";
    
    for(int i = 0; i<11; i++){
        switch(i){
            case 0:
                os << "|"; break;
            case 1:
                os << "%"; break;
            case 2:
                os << "%"; break;
            case 3:
                os << "|"; break; // XX
            case 4:
                os << "|"; break;
            case 5:
                os << "%"; break;
            case 6:
                os << "%"; break;
            default: //cases 7 to 10
                os << "|"; break;
        }
        
        //check if double int (ex. 10), single int (ex. 8), or empty space
        if (i!=5 && i!=10){
            if(row.qwinRow[i] < 10 && row.qwinRow[i] != 0){
                os << " " << row.qwinRow[i];
            }else if(row.qwinRow[i] > 9){
                os << row.qwinRow[i];
            }else
                os << "  ";
        }
    }
    os << std::endl;
    return os;
}

