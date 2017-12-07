//
//  QwintoRow.cpp
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#include <stdio.h>
#include "QwintoRow.h"
#include "Colour.h"
#include <iostream>

// --- Implementation of QwintoRow Class Functions ---

//implementing the insertion operator to print the QwintoRow to an output stream
std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::RED>& row){
    os << "Red" << "\t\t\t";

    for(int i = 0; i<11; i++){ //loop over all the rows
        switch (i) { //covering all the possible cases
            case 0:
                os << "|"; break;
            case 1:
                os << "%"; break;
            case 2:
                os << "%"; break;
            case 3:
                os << "|XX"; break;
            case 5:
                os << "%"; break;
            case 6:
                os << "%"; break;
            default:
                os << "|"; break;
        }
        
        //check if double int (ex. 10), single int (ex. 8), or empty space
        if (i!=3 && i!=10){
            if(row.qwinRow[i] < 10 && row.qwinRow[i] != 0){ //single digit
                os << " " << row.qwinRow[i];
            }else if(row.qwinRow[i] > 9){ //double digit
                os << row.qwinRow[i];
            }else //empty
                os << "  ";
        }
    }
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::YELLOW>& row){
    os << "Yellow" << "\t ";

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

std::ostream& operator<<(std::ostream& os, const QwintoRow<Colour::BLUE>& row){
    os << "Blue" << "  ";

    for(int i = 0; i<11; i++){
        switch(i){
            case 2:
                os << "%"; break;
            case 3:
                os << "%"; break;
            case 4:
                os << "|XX"; break;
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

