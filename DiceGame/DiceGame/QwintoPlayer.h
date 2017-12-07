//
//  QwintoPlayer.h
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#ifndef QwintoPlayer_h
#define QwintoPlayer_h
#include "Player.h"
#include "QwintoScoreSheet.h"


class QwintoPlayer : public Player {
public:
    QwintoScoreSheet qss;
    QwintoPlayer(QwintoScoreSheet qwintoScoreSheet);
    void inputBeforeRoll(RollOfDice& rd);
    void inputAfterRoll(RollOfDice& rd);
    
};

#endif /* QwintoPlayer_h */
