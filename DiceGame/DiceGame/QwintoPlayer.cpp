//
//  QwintoPlayer.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-28.
//  Copyright © 2017 Haider. All rights reserved.
//

#include "QwintoPlayer.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>


// --- Implementation of ScoreSheet Class Functions ---

//implementing constructor
QwintoPlayer::QwintoPlayer(QwintoScoreSheet qwintoScoreSheet) : qss(qwintoScoreSheet){
    activePlayer = false;
}

//implementing input before roll
void QwintoPlayer::inputBeforeRoll(RollOfDice& rd){
    std::string userInput = ""; //store user input
    bool redDice = false, yellowDice = false, blueDice = false;
    std::vector<Dice> userColours; //store user selected dice
    
    std::cout<< "Please enter the dice you want to roll, type '.' when done: ";
    while((userColours.size() == 0) || (userInput != ".")){
        std::cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); //transforming user input to lowercase

        
        //insert the corresponding dice into the vector, but make sure to include it only once (bool used for that)
        if(userInput == "red" && redDice==false){
            userColours.push_back(Dice(Colour::RED));
            redDice = true;
        }
        else if(userInput == "yellow" && yellowDice==false){
            userColours.push_back(Dice(Colour::YELLOW));
            yellowDice = true;
        }
        else if(userInput == "blue" && blueDice==false){
            userColours.push_back(Dice(Colour::BLUE));
            blueDice = true;
        }
        else if(userColours.size() == 0){
            std::cout << "Invalid input! Please select at least one dice!" << std::endl;
        }
        else if(userInput != "."){
            std::cout << "Invalid input! Please type '.' once done selecting dice" << std::endl;
        }
    }
    
    //create a roll of dice based on user selection
    rd = RollOfDice(userColours);
}

//implementing input after roll
void QwintoPlayer::inputAfterRoll(RollOfDice& rd){
    bool finished = false;
    std::vector<Dice> userColours; //store user selected dice
    
    //check if active player's turn and decide if pass roll or fail to record roll
    while(finished == false){
        
        std::string userInput = "";
        std::string userColumnInput = "";
        int columnNumber = 0;
        
        std::cout << "What row (red,yellow,blue) would you like to record your score in?" << std::endl;
        
        //notify player that he can skip or fail turn based on active player or not
        if(!activePlayer) std::cout << "--- Type 'skip' if you wish to skip this roll ---" << std::endl;
        else std::cout << "--- Type 'fail' to record a failed throw ---" << std::endl;
        
        std::cout << "Enter row colours: ";
        std::cin >> userInput; //get user input for row choicce
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); //transforming user input to lowercase
        
        //if player decides not to skip or fail turn, prompt for column #
        if(userInput!="fail" && userInput!="skip"){
            std::cout << "Please enter the column [1 - 9] you wish to record your dice roll in: ";
            
            bool valid = false;
            
            //ensure user entered a valid coloumn number
            while(valid == false){
                std::cin >> userColumnInput;
                columnNumber = std::stoi(userColumnInput); //convert string to int
                
                if(columnNumber > 9 || columnNumber < 1){  //check to see if user inut is correct
                    std::cout << "Please enter a valid number [1 - 9]: ";
                    std::cin >> userColumnInput;
                    columnNumber = std::stoi(userColumnInput); //convert string to int
                }else{
                    valid = true;
                }
            }
        }
        
        columnNumber--; //since it is stored as [0-8]
        
        if(activePlayer && userInput == "fail"){ //active player chooses to not record
            qss.failedAttempts++; //increment failed throws
            finished = true; //turn finished
        }else if(!activePlayer && userInput == "skip"){ //non-active player chooses to not record
            finished = true;
        }else if(userInput == "red"){ //check to see if user wants to enter in red row
            if(qss.score(rd, Colour::RED,columnNumber)){ //score returns a boolean
                qss.redRow[columnNumber] = rd;
                finished = true;
            }
        }else if(userInput == "blue"){ //check to see if user wants to enter in red row
            if(qss.score(rd, Colour::BLUE,columnNumber)){ //score returns a boolean
                qss.blueRow[columnNumber] = rd;
                finished = true;
            }
        }else if(userInput == "yellow"){ //check to see if user wants to enter in red row
            if(qss.score(rd, Colour::YELLOW,columnNumber)){ //score returns a boolean
                qss.yellowRow[columnNumber] = rd;
                finished = true;
            }
        }
        
        if(finished == false)
            std::cout << "Invalid row colour, try again!" << std::endl; //if user doesn't enter red, blue, or yellow
    
        

        
        
    }
}

