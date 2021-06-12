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
    randomSelectedMove = MoveType::NONE;
}

void Move::print() {
    if (move == MoveType::UP) std::cout << "UP ";
    else if (move == MoveType::RIGHT) std::cout << "RIGHT ";
    else if (move == MoveType::DOWN) std::cout << "DOWN ";
    else if (move == MoveType::LEFT) std::cout << "LEFT ";
    else if (move == MoveType::TAKE) std::cout << "TAKE ";
    else if (move == MoveType::STOP) std::cout << "STOP ";
    else if (move == MoveType::RANDOM) {
        if(randomSelectedMove == MoveType::UP) std::cout << "*UP ";
        else if (randomSelectedMove == MoveType::RIGHT) std::cout << "*RIGHT ";
        else if (randomSelectedMove == MoveType::DOWN) std::cout << "*DOWN ";
        else if (randomSelectedMove == MoveType::LEFT) std::cout << "*LEFT ";
        else if (randomSelectedMove == MoveType::TAKE) std::cout << "*TAKE ";
        else if (randomSelectedMove == MoveType::STOP) std::cout << "*STOP ";
        else std::cout << "RANDOM ";
    }
}

std::string Move::toString() {
    if (move == MoveType::UP) return "UP ";
    else if (move == MoveType::RIGHT) return "RIGHT ";
    else if (move == MoveType::DOWN) return "DOWN ";
    else if (move == MoveType::LEFT) return "LEFT ";
    else if (move == MoveType::TAKE) return "TAKE ";
    else if (move == MoveType::STOP) return "STOP ";
    else if (move == MoveType::RANDOM) {
        if(randomSelectedMove == MoveType::UP) return "*UP ";
        else if (randomSelectedMove == MoveType::RIGHT) return "*RIGHT ";
        else if (randomSelectedMove == MoveType::DOWN) return "*DOWN ";
        else if (randomSelectedMove == MoveType::LEFT) return "*LEFT ";
        else if (randomSelectedMove == MoveType::TAKE) return "*TAKE ";
        else if (randomSelectedMove == MoveType::STOP) return "*STOP ";
        else return "RANDOM ";
    }
}

MoveType Move::getMove() {
    return move;
}

void Move::setMove(MoveType mType) {
    move = mType;
}

void Move::setRandom() {
    int randomNumber = rand() % 6;
    if (randomNumber == 0) randomSelectedMove = MoveType::UP;
    else if (randomNumber == 1) randomSelectedMove = MoveType::RIGHT;
    else if (randomNumber == 2) randomSelectedMove = MoveType::DOWN;
    else if (randomNumber == 3) randomSelectedMove = MoveType::LEFT;
    else if (randomNumber == 4) randomSelectedMove = MoveType::TAKE;
    else if (randomNumber == 5) randomSelectedMove = MoveType::STOP;
}
MoveType Move::getRandomSelectedMove() {
    return randomSelectedMove;
}

std::string Move::getMoveName() {
    if (move == MoveType::UP) return "UP ";
    else if (move == MoveType::RIGHT) return "RIGHT ";
    else if (move == MoveType::DOWN) return "DOWN ";
    else if (move == MoveType::LEFT) return "LEFT ";
    else if (move == MoveType::TAKE) return "TAKE ";
    else if (move == MoveType::STOP) return "STOP ";
    else if (move == MoveType::RANDOM) {
        if(randomSelectedMove == MoveType::UP) return "*UP ";
        else if (randomSelectedMove == MoveType::RIGHT) return "*RIGHT ";
        else if (randomSelectedMove == MoveType::DOWN) return "*DOWN ";
        else if (randomSelectedMove == MoveType::LEFT) return "*LEFT ";
        else if (randomSelectedMove == MoveType::TAKE) return "*TAKE ";
        else if (randomSelectedMove == MoveType::STOP) return "*STOP ";
        else return " ";

    }
}
