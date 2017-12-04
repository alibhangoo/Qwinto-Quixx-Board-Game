//
//  QwintoPlayer.h
//  DiceGame
//
//  Created by Haider on 2017-11-26.
//  Copyright © 2017 Haider. All rights reserved.
//

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
