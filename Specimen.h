#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <iostream>
#include <vector>
#include "Move.h"
#include "Board.h"

typedef std::pair<int, int> Cooridinates;

class Specimen
{
public:
    Specimen(int length, int side, int startX, int startY);
    Specimen();
    void print();
    std::vector<Move>& getMovesVector();
    void mutate(int mutationProbability);
    MoveType getRandomMove();
    void calculateGrade();
    bool checkPosition(int xPosition, int yPosition);
    void checkUp();
    void checkRight();
    void checkDown();
    void checkLeft();
    void take();
    void stop();
    bool checkEgg();
    double getGrade();
    int getCollectedEggs();
    int getActionCounter();
    void rabbitPositionsPushBack(int x, int y);
    std::vector <Cooridinates> &getRabbitPositions();
    void printRabbitPostions();
    int getStartX();
    int getStartY();


    //std::vector <Cooridinates> getBestSpecimenPositions();


private:
    std::vector <Move> moves;
    int length;
    int side;
    double grade;
    int xPosition;
    int yPosition;
    int startX;
    int startY;
    int collectedEggs;
    int actionsCounter;
    std::vector <Cooridinates> colectedEggsCoordiantes;
    std::vector <Cooridinates> rabbitPositions;

};



#endif // SPECIMEN_H
