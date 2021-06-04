#pragma once
#include <iostream>
enum class FieldType {
	WALL, EMPTY, EGG
};

/*std::ostream& operator << (std::ostream& os, const FieldType obj) {
	//const char* fieldTypes[] = { "WALL","EMPTY","EGG" };
	//os << static_cast<std::underlying_type<FieldType>::type>(obj);
	//os << fieldTypes[obj];
	os << "haha";
	return os;
}*/
