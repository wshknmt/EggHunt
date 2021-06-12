#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdlib>
#include "Field.h"

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
private:
    int side;
    std::vector <std::vector<Field> > fields;
    int eggsAmount;
    static Board* pInstance;
};

#endif // BOARD_H
