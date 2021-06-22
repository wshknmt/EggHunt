#ifndef FIELD_H
#define FIELD_H

#include "FieldType.h"
#include <iostream>
#define SEED 100
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

#endif // FIELD_H
