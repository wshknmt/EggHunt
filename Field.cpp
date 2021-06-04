#include "Field.h"
#include <cstdlib>
#include <iostream>


Field::Field() {
	int number = std::rand() % 11;
	if (number < 8)
		type = FieldType::EMPTY;
	else
		type = FieldType::WALL;
}

void Field::print() {
	//const char* fieldTypes[] = { "WALL", "EMPTY", "EGG" };
	//std::cout << fieldTypes[type] << " ";
	if (type == FieldType::WALL) std::cout << "WALL ";
	else if (type == FieldType::EMPTY) std::cout << "EMPTY ";
	else if (type == FieldType::EGG) std::cout << "EGG ";
}

FieldType Field::getType() {
	return type;
}

void Field::setType(FieldType fType) {
	type = fType;
}

