#ifndef MOVE_H
#define MOVE_H

#include "MoveType.h"
class Move
{
public:
    Move();
    void print();
    MoveType getMove();
    std::string getMoveName();
    void setMove(MoveType mType);
    void setRandom();
    MoveType getRandomSelectedMove();
    std::string toString();
private:
    MoveType move;
    MoveType randomSelectedMove;
};

#endif // MOVE_H
