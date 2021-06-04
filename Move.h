#pragma once
#include "MoveType.h"
class Move
{
public:
	Move();
	void print();
	MoveType getMove();
	void setMove(MoveType mType);
	void setRandom();
	MoveType getRandomSelectedMove();
private:
	MoveType move;
	MoveType randomSelectedMove;
};

