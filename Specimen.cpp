#include "Specimen.h"
#include<algorithm>
Specimen::Specimen(int length, int side, int startX, int startY) {
    this->length = length;
    this->side = side;
    grade = 0;
    this->startX = startX;
    this->startY = startY;
    for (int i = 0; i < length; i++) {
        Move move;
        moves.push_back(move);
    }
}

Specimen::Specimen() {

}

void Specimen::print() {
    for (unsigned int i = 0; i < moves.size(); i++) {
        moves[i].print();
    }
    std::cout << std::endl;
}

std::string Specimen::toString() {
    std::string spec;
    for (unsigned int i = 0; i < moves.size(); i++) {
        spec += moves[i].toString();
    }
    return spec;
}

std::vector<Move>& Specimen::getMovesVector() {
    return moves;
}

void Specimen::mutate(int mutationProbability) {
    int randomNumber = rand() % moves.size();
    if (rand() % 100 <= mutationProbability) {
        moves[randomNumber].setMove(getRandomMove());
    }
}

MoveType Specimen::getRandomMove() {
    int randomNumber = rand() % 6;
    if (randomNumber == 0) return MoveType::UP;
    else if (randomNumber == 1) return MoveType::RIGHT;
    else if (randomNumber == 2) return MoveType::DOWN;
    else if (randomNumber == 3) return MoveType::LEFT;
    else if (randomNumber == 4) return MoveType::TAKE;
    else if (randomNumber == 5) return MoveType::STOP;
    else return MoveType::STOP;
}

bool Specimen::checkPosition(int xPosition, int yPosition) {
    if (xPosition < 0 || xPosition >= side || yPosition < 0 || yPosition >= side) return false;
    else if(Board::getInstance()->getFields()[yPosition][xPosition].getType() == FieldType::WALL) return false;
    return true;
}

void Specimen::checkUp() {
    actionsCounter++;
    if (checkPosition(xPosition, yPosition - 1)) {
        yPosition--;
    }
}
void Specimen::checkRight() {
    actionsCounter++;
    if (checkPosition(xPosition + 1, yPosition)) {
        xPosition++;
    }
}
void Specimen::checkDown() {
    actionsCounter++;
    if (checkPosition(xPosition, yPosition + 1)) {
        yPosition++;
    }
}
void Specimen::checkLeft() {
    actionsCounter++;
    if (checkPosition(xPosition - 1, yPosition)) {
        xPosition--;
    }
}

void Specimen::take() {
    actionsCounter++;
    if (checkEgg()) {

        Cooridinates coordinates;
        coordinates.first = xPosition;
        coordinates.second = yPosition;
        colectedEggsCoordiantes.push_back(coordinates);
        collectedEggs++;
        Board::getInstance()->setField(FieldType::EMPTY, xPosition, yPosition);
    }
}
void Specimen::stop() {
    if (collectedEggs < EGGS_AMOUNT) actionsCounter++;
}

bool Specimen::checkEgg() {
    if (Board::getInstance()->getFields()[yPosition][xPosition].getType() == FieldType::EGG)
        return true;
    return false;
}

void Specimen::calculateGrade() {
    rabbitPositions.clear();
    xPosition = startX;
    yPosition = startY;
    collectedEggs = 0;
    actionsCounter = 0;
    rabbitPositionsPushBack(xPosition, yPosition);
    for (unsigned int i = 0; i < moves.size(); i++) {
        if (moves[i].getMove() == MoveType::UP) checkUp();
        else if (moves[i].getMove() == MoveType::RIGHT) checkRight();
        else if (moves[i].getMove() == MoveType::DOWN) checkDown();
        else if (moves[i].getMove() == MoveType::LEFT) checkLeft();
        else if (moves[i].getMove() == MoveType::TAKE) take();
        else if (moves[i].getMove() == MoveType::STOP) stop();
        else if (moves[i].getMove() == MoveType::RANDOM) {
            moves[i].setRandom();
            if (moves[i].getRandomSelectedMove() == MoveType::UP) checkUp();
            else if (moves[i].getRandomSelectedMove() == MoveType::RIGHT) checkRight();
            else if (moves[i].getRandomSelectedMove() == MoveType::DOWN) checkDown();
            else if (moves[i].getRandomSelectedMove() == MoveType::LEFT) checkLeft();
            else if (moves[i].getRandomSelectedMove() == MoveType::TAKE) take();
            else if (moves[i].getRandomSelectedMove() == MoveType::STOP) stop();
        }
        rabbitPositionsPushBack(xPosition, yPosition);
    }
    grade = 1.0 * (float)collectedEggs / (float)actionsCounter;
    std::for_each(colectedEggsCoordiantes.begin(), colectedEggsCoordiantes.end(),
        [&](const Cooridinates& c) { Board::getInstance()->setField(FieldType::EGG, c.first, c.second); });
}

double Specimen::getGrade() {
    return grade;
}

int Specimen::getCollectedEggs() {
    return collectedEggs;
}
int Specimen::getActionCounter() {
    return actionsCounter;
}

void Specimen::rabbitPositionsPushBack(int x, int y) {
    Cooridinates coordinates;
    coordinates.first = x;
    coordinates.second = y;
    rabbitPositions.push_back(coordinates);
}

std::vector <Cooridinates> &Specimen::getRabbitPositions() {
    return rabbitPositions;
}

void Specimen::printRabbitPostions() {
    for(unsigned int i = 0; i < rabbitPositions.size(); i++) {
        std::cout <<"x: "<< rabbitPositions[i].first<<" y: "<<rabbitPositions[i].second<<std::endl;
    }
}

int Specimen::getStartX() {
    return startX;
}
int Specimen::getStartY() {
    return startY;
}
