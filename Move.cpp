#include "Move.h"
#include <cstdlib>
#include <iostream>


Move::Move() {
	int randomNumber = rand() % 7;
	if (randomNumber == 0) move = MoveType::UP;
	else if (randomNumber == 1) move = MoveType::RIGHT;
	else if (randomNumber == 2) move = MoveType::DOWN;
	else if (randomNumber == 3) move = MoveType::LEFT;
	else if (randomNumber == 4) move = MoveType::RANDOM;
	else if (randomNumber == 5) move = MoveType::TAKE;
	else if (randomNumber == 6) move = MoveType::STOP;
}

void Move::print() {
	if (move == MoveType::UP) std::cout << "UP ";
	else if (move == MoveType::RIGHT) std::cout << "RIGHT ";
	else if (move == MoveType::DOWN) std::cout << "DOWN ";
	else if (move == MoveType::LEFT) std::cout << "LEFT ";
	else if (move == MoveType::RANDOM) std::cout << "RANDOM ";
	else if (move == MoveType::TAKE) std::cout << "TAKE ";
	else if (move == MoveType::STOP) std::cout << "STOP ";
}

MoveType Move::getMove() {
	return move;
}

void Move::setMove(MoveType mType) {
	move = mType;
}

void Move::setRandom() {
	int randomNumber = rand() % 6;
	if (randomNumber == 0) move = MoveType::UP;
	else if (randomNumber == 1) move = MoveType::RIGHT;
	else if (randomNumber == 2) move = MoveType::DOWN;
	else if (randomNumber == 3) move = MoveType::LEFT;
	else if (randomNumber == 5) move = MoveType::TAKE;
	else if (randomNumber == 6) move = MoveType::STOP;
	randomSelectedMove = move;
}
MoveType Move::getRandomSelectedMove() {
	return randomSelectedMove;
}
