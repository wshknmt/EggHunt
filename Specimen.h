#pragma once
#include <iostream>
#include <vector>
#include "Move.h"
#include "Board.h"

typedef std::pair<int, int> CollectedEggPosition;

class Specimen
{
public:
	Specimen(int length, int side);
	Specimen();
	void print();
	std::vector<Move>& getMovesVector();
	void mutate(int mutationProbability);
	MoveType getRandomMove();
	void calculateGrade();
	bool checkPosition(int xPosition, int yPosition);
	void checkUp();
	void checkRight();
	void checkDown();
	void checkLeft();
	void take();
	void stop();
	bool checkEgg();
	float getGrade();
	int getCollectedEggs();
	int getActionCounter();


private:
	std::vector <Move> moves;
	int length;
	int side;
	double grade;
	int xPosition;
	int yPosition;
	int collectedEggs;
	int actionsCounter;
	std::vector <CollectedEggPosition> collectedEggPositions;

};

