#pragma once
#include <iostream>
#include <vector>
#include "Specimen.h"
#include "Board.h"
class Population
{
public:
	Population();
	Population(int size, int specimenLength, int side, Board board);
	void print();
	void singleCrossover();
	void crossover(std::vector <Move>& mV1, std::vector <Move>& mV2, int number);
	Population selection();
	void mutate();
	void updatePopulation();
	double getHighestGrade();
	Specimen getBestSpec();
	

private:
	int size;
	std::vector <Specimen> specimens;
	Board board;
	double highestGrade;
	Specimen bestSpec;
};

