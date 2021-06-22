#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdlib>
#include "Field.h"
#include <ctime>
#include <random>


#define SIDE 20
#define EGGS_AMOUNT 60


class Board {
public:
    static Board* getInstance();
    Board();
    Board(int side, int eggsAmount);
    void setRandom();
    void print();
    std::vector <std::vector<Field> > getFields();
    void setField(FieldType type, int x, int y);
    void setStartPosition();
    int getStartX();
    int getStartY();
private:
    int side;
    std::vector <std::vector<Field> > fields;
    int eggsAmount;
    static Board* pInstance;
    int startX;
    int startY;
};

#endif // BOARD_H
