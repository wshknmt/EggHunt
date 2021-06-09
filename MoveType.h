#pragma once
#include <iostream>
enum class MoveType {
	UP, RIGHT, DOWN, LEFT, RANDOM, TAKE, STOP, NONE
};

/*std::ostream& operator << (std::ostream& os, const Move& obj) {
	os << static_cast<std::underlying_type<Move>::type>(obj);
	return os;
}*/
