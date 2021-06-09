#pragma once
#include <vector>
#include <cstdlib>
#include "Field.h"

#define SIDE 5
#define EGGS_AMOUNT 5

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

