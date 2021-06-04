#pragma once
#include <vector>
#include <cstdlib>
#include "Field.h"
class Board {
public:
	Board();
	Board(int side, int eggsAmount);
	void setRandom();
	void print();
	std::vector <std::vector<Field> > getFields();

private:
	int side;
	std::vector <std::vector<Field> > fields;
	int eggsAmount;
};

