//
//  QwintoScoreSheet.cpp
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#include <stdio.h>
#include <string>
#include "QwintoScoreSheet.h"

// --- Implementation of QwintoScoreSheet Class Functions ---

//constructor, initializing members
QwintoScoreSheet::QwintoScoreSheet(const std::string& name){
    //initialize all
    playerName = name;
    failedAttempts = 0;
    overallScore = 0;
    QwintoRow<Colour::RED> redRow();
    QwintoRow<Colour::BLUE> blueRow();
    QwintoRow<Colour::YELLOW> yellowRow();
}

//implementing function to set and return the points for the final score
int QwintoScoreSheet::calcTotal(){
    
    int totalScore = 0;
    int counterRed = 0, counterBlue = 0, counterYellow = 0;
    
    totalScore -= failedAttempts*5; //subtract 5 points for each failed attempt
    
    //check to see if the row is completed
    for(int i = 0; i < 10; i++){
        if(i!=3 && redRow[i] > 0)
            counterRed++;
        if(i!=4 && blueRow[i] > 0)
            counterBlue++;
        if(i!=5 && yellowRow[i] > 0)
            counterYellow++;
    }
    
    //add scores to total score for each row, check to see if row is full (if it is add the last number, if not get total numbers in that row
    (counterRed == 9) ? (totalScore += redRow[9]) : (totalScore += counterRed);
    (counterYellow == 9) ? (totalScore += yellowRow[9]) : (totalScore += counterYellow);
    (counterBlue == 9) ? (totalScore += blueRow[9]) : (totalScore += counterBlue);

    //check to see if player scored any points in overlapping columns [BONUS POINT CALCULATION]
    for(int i = 0; i < 6; i++){
        if(redRow[i] > 0 && yellowRow[i+1]>0 && blueRow[i+2]>0){
            switch(i){
                case 0:
                    totalScore += blueRow[i+2]; break; //bonus point for blue row (col 0) [using red row as reference]
                case 1:
                    totalScore += redRow[i]; break; //bonus point for red row (col 1)
                case 5:
                    totalScore += redRow[i]; break; //bonus point for red row (col 5)
                case 6:
                    totalScore += yellowRow[i+1]; break; //bonus point for yellow row (col 6)
                case 7:
                    totalScore += blueRow[i+2]; break; //bonus point for blue row (col 7)
                default:
                    break;
        }
    }
    }

    return totalScore; //return total score
}


//implementing function to set and return the points for the final score
void QwintoScoreSheet::setTotal(){
    overallScore = calcTotal();
}

//implementing destructor
QwintoScoreSheet::~QwintoScoreSheet(){}

//implementing the not operator, it indicates if the game has ended or not
bool const QwintoScoreSheet::operator! (){
    
    //check to see if 2 rows are completed full
    int counterRed = 0, counterBlue = 0, counterYellow = 0, completeRowCounter = 0;
    
    //check to see if the row is completed
    for(int i = 0; i < 10; i++){
        if(i!=3 && redRow[i] > 0)
            counterRed++;
        if(i!=4 && blueRow[i] > 0)
            counterBlue++;
        if(i!=5 && yellowRow[i] > 0)
            counterYellow++;
    }
    
    //add scores to total score for each row, check to see if row is full (if it is add the last number, if not get total numbers in that row
    if(counterRed == 9) (completeRowCounter++);
    if(counterYellow == 9) (completeRowCounter++);
    if(counterBlue == 9) (completeRowCounter++);

    return (failedAttempts==4 || completeRowCounter >= 2);
}

//implementing validate function to check if a roll of dice can be entered at a specific position
bool QwintoScoreSheet::validate(RollOfDice rd, Colour colourSelected, int leftPosition){
    
    bool hasColour = false;
    
    //check if the user selected colour is included in the roll of the dice
    for(Dice d : rd.vDice){
        if(d.colour == colourSelected) hasColour = true;
    }
    if(hasColour == false) return false; //this
    
    //check for same number in overlapping columns
    switch(colourSelected){
        case Colour::RED:
            
            if(leftPosition == 8 && yellowRow[9] == rd) return false; //check if 2nd last column in red is equal to last column in yellow
            //if position is less than 8, compare red row to both other rows to check for same overlapping numbers
            else if (leftPosition<8 && (blueRow[leftPosition+2] == rd || yellowRow[leftPosition+1]==rd)) return false;
            return redRow.validate(rd, leftPosition); //call RollOfDice validate function to check it is a legal position to place roll in
            
        case Colour::BLUE:
            
            if(leftPosition == 1 && yellowRow[0] == rd) return false;
            else if (leftPosition>1 && (redRow[leftPosition-2] == rd || yellowRow[leftPosition-1]==rd)) return false;
            return blueRow.validate(rd, leftPosition);
            
        case Colour::YELLOW:
            
            if((leftPosition == 0 && blueRow[1] == rd) || (leftPosition == 9 && redRow[8] == rd)) return false;
            else if (leftPosition<9 && (blueRow[leftPosition+1] == rd || redRow[leftPosition-1]==rd)) return false;
            return yellowRow.validate(rd, leftPosition);
            
        default:
            return false;
    }
    return true;
}

//implementing the overloaded insterion operator
std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qss){
    //output is modelled to look like the one provided in the assignment exmaple
    os <<"\nPlayer name: " << qss.playerName;
    os <<"\t\t\t\t Points: " << qss.overallScore << std::endl;
    os << "\t\t\t--------------------------------" << std::endl;

    os << qss.redRow; //printing red row
    os << "\t     ----------------------------------" << std::endl;

    os << qss.yellowRow; //printing yellow row
    os << "\t  ----------------------------------" << std::endl;

    os << qss.blueRow; //printng blue row
    os << "\t  -------------------------------" << std::endl;

    os << "Failed throws: " << qss.failedAttempts << "\n" << std::endl;

    return os;
}
