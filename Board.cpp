#include "Board.h"

Board* Board::pInstance = nullptr;

Board::Board(int side, int eggsAmount) {
    this->side = side;
    this->eggsAmount = eggsAmount;

    for (int i = 0; i < side; i++) {
        std::vector<Field> v1;
        for (int j = 0; j < side; j++) {
            Field field;
            v1.push_back(field);
        }
        fields.push_back(v1);
    }
}
Board::Board() {

}

Board* Board::getInstance() {
    if (!pInstance)
        pInstance = new Board(SIDE, EGGS_AMOUNT);
    return pInstance;
}

void Board::setRandom() {
    int deplyedEggs = 0;
    while (deplyedEggs < eggsAmount) {
        int x = std::rand() % side;
        int y = std::rand() % side;
        if (fields[x][y].getType() == FieldType::EMPTY) {
            fields[x][y].setType(FieldType::EGG);
            deplyedEggs++;
        }
    }
}

void Board::setField(FieldType type, int x, int y) {
    fields[y][x].setType(type);
}

void Board::print() {

    for (unsigned int i = 0; i < fields.size(); i++) {
        for (unsigned int j = 0; j < fields[i].size(); j++)
            fields[i][j].print();
        std::cout << std::endl;
    }
}

std::vector <std::vector<Field> > Board::getFields() {
    return fields;
}
