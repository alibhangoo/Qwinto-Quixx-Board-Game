//
//  QwintoScoreSheet.h
//  DiceGame
//
//  Name: Ali Bhangoo
//  Student #: 7828675

#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h

#include "Colour.h"
#include "QwintoRow.h"
#include "ScoreSheet.h"

class QwintoScoreSheet : public ScoreSheet {
public:
    //colours of the 3 rows
    QwintoRow <Colour::RED> redRow;
    QwintoRow <Colour::BLUE> blueRow;
    QwintoRow <Colour::YELLOW> yellowRow;
    
    QwintoScoreSheet(const std::string& playerName);
    ~QwintoScoreSheet();
    void setTotal();
    int calcTotal();
    bool const operator! ();
    friend std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qss);
    
protected:
    bool validate(RollOfDice rd, Colour colourSelected, int leftPosition = -1);
    
};

#endif /* QwintoScoreSheet_h */
