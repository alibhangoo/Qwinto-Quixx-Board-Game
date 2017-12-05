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

using namespace std;

int main() {
    
    std::string gameType = "";
    std::string winnerPlayerName = "";
    int totalPlayers = 0;
    std::vector<std::string> playerNames; //vector filled with player names
    std::string playerName = "";
    bool finished = false;
    RollOfDice rd;
    int playerTurn = 0, currentPlayer = 0; //ex. player 0, player 1 ... player x
    
    std::vector<QwintoPlayer> qwinPlayer;
    
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
    while(totalPlayers <= 0 || totalPlayers >=3){
        std::cout<<"Please enter the number of players [1 - 3]: ";
        std::cin >> totalPlayers;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
    

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
            
            currentQwintoPlayer.inputBeforeRoll(rd); //call input before roll to prompt player for info about dice
            rd.roll(); //roll dice
            
            std::cout << rd; //print the roll
            std::cout << currentQwintoPlayer.qss; //print scoresheet of active player
            
            currentQwintoPlayer.inputAfterRoll(rd); //get input from active player after roll
            currentQwintoPlayer.qss.setTotal(); //score dice according to input form active player
            std::cout << currentQwintoPlayer.qss; //print scoresheet of active player

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
                if(!qwinPlayer.at(i).qss){ //if overloaded not operator returns true, game had ended
                    std::cout << "----------------------- GAME OVER -----------------------" << std::endl;
                    finished = true;
                }
            }
            
            currentQwintoPlayer.activePlayer = false; //player turn is over
            playerTurn++; //next players turn
        }
    }
    
    int indexOfWinner, winnerScore = qwinPlayer.at(0).qss.overallScore;
    
    //loop over all players to calculate total points & find the winner
    for(int i=0; i<totalPlayers; i++){
        qwinPlayer.at(i).qss.setTotal();//calculate points for each player
        
        //find winner
        if(winnerScore < qwinPlayer.at(i).qss.overallScore){
            winnerScore = qwinPlayer.at(i).qss.overallScore;
            indexOfWinner = i;
        }
        std:: cout << qwinPlayer.at(i).qss;
    }
    //print the winner
    std::cout << "Congrats " << qwinPlayer.at(indexOfWinner).qss.playerName << ". You won! Score: " << qwinPlayer.at(indexOfWinner).qss.overallScore << std::endl;
}

