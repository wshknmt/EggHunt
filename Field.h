#pragma once
#include "FieldType.h"
#include <iostream>

class Field
{
public:
	Field();
	void print();
	FieldType getType();
	void setType(FieldType fType);

private:
	FieldType type;

};

