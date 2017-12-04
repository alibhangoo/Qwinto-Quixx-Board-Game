//
//  main.cpp
//  DiceGame
//
//  Created by Haider on 2017-11-20.
//  Copyright © 2017 Haider. All rights reserved.
//

#include <iostream>
#include <random>
#include "Dice.h"
#include "RollOfDice.h"
#include "Player.h"
#include "QwintoRow.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"

using namespace std;

int main() {
    
    std::string gameType = "";
    int totalPlayers = 0;
    std::vector<std::string> playerNames; //vector filled with player names
    std::string playerName = "", winnerPlayerName = "";
    bool finished = false;
    RollOfDice rd;
    int playerTurn = 0, currentPlayer = 0, winnerScore = -1; //ex. player 0, player 1 ... player x
    
    std::vector<QwintoPlayer> qwinPlayer;
    std::vector<QwixxPlayer> qwixPlayer;
    
    RollOfDice dice; //create a RollOfDice for the game
    
    //prompt user for game type
    while(gameType != "qwinto" && gameType != "qwixx"){
        std::cout << "Please choose the game type (qwinto or qwixx): ";
        std::cin >> gameType;
        std::transform(gameType.begin(), gameType.end(), gameType.begin(), ::tolower); //transforming user input to lowercase
    }
    
    if(gameType == "qwixx"){
        std::cout<<"This version of the game has not been implemented due to doing the project alone!"<<std::endl;
        return 0;
    }
    
    //promot user for # of players in the game
    std::cout<<"Please enter the number of players [1 - 3]: ";
    do{
        while(!(std::cin >> totalPlayers)){
            std::cout << "Please enter [1 - 3]. \n";
            std::cin.clear(); //clear error flag
            std::cin.ignore(10000, '\n'); //skip to next new line
        }
    }while(totalPlayers <= 0 || totalPlayers >=3);

    //prompt user for player names:
    std::cout << "Please enter player names!" << std::endl;
    for(int i = 0; i<totalPlayers; i++){
        std::cout<< "Player " << (i+1) << " Name: ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
    }
    
    //main while loop for either qwinto or qwixx game
    if(gameType == "qwinto"){
        for(int i = 0; i < totalPlayers; i++){
            QwintoScoreSheet qss(playerNames.at(i)); //create a qwinto scoresheet for each player
            qwinPlayer.push_back(QwintoPlayer(qss)); //create a qwintoplayer and add it to the vector
        }
        
        //loop till game is finished
        while(finished == false){
            //set the current player
            currentPlayer = playerTurn%totalPlayers;
            //get the current qwinto player from the vector of players
            QwintoPlayer& currentQwintoPlayer = qwinPlayer.at(currentPlayer);
            
            currentQwintoPlayer.activePlayer = true; //set active player to true for the current player
            std::cout << currentQwintoPlayer.qss;
            
            currentQwintoPlayer.inputBeforeRoll(rd); //call input before roll to prompt player for info about dice
            rd.roll(); //roll dice
            std::cout << rd; //print the roll
            std::cout << currentQwintoPlayer.qss; //print scoresheet of active player
            currentQwintoPlayer.inputAfterRoll(rd); //get input from active player after roll
            currentQwintoPlayer.qss.setTotal(); //score dice according to input form active player
            std::cout << currentQwintoPlayer.qss;

            //loop over all non-active players
            for(int i=0;i<totalPlayers;i++){
                if(i != currentPlayer){
                    std::cout << qwinPlayer.at(i).qss; //print scoresheet of non-active player
                    qwinPlayer.at(i).inputAfterRoll(rd); //get input from non-active player (to pass or record throw)
                    qwinPlayer.at(i).qss.setTotal();
                    std::cout << qwinPlayer.at(i).qss;
                }
            }
            
            for(int i=0; i< totalPlayers; i++){
                if(!qwinPlayer.at(i).qss) finished = true;
            }
            
            playerTurn++; //next players turn
            currentQwintoPlayer.activePlayer = false; //player turn is over
            
        }
        
        //loop over all players to calculate total points
        for(int i=0; i<totalPlayers; i++){
            qwinPlayer.at(i).qss.setTotal();//calculate points for each player
            std::cout << qwinPlayer.at(i).qss; //print scoresheet
            
            //find winner
            if(qwinPlayer.at(i).qss.overallScore > winnerScore){
                winnerPlayerName = qwinPlayer.at(i).qss.playerName;
                winnerScore = qwinPlayer.at(i).qss.overallScore;
            }
        }
    }
    
    //print the winner
    std::cout << "CONGRATS!" << winnerPlayerName << " You won! Score: " << winnerScore << std::endl;
    
}

