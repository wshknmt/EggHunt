#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include "Specimen.h"
#include "Board.h"
class Population
{
public:
    Population();
    Population(int size, int specimenLength, int side);
    void print();
    void singleCrossover();
    void crossover(std::vector <Move>& mV1, std::vector <Move>& mV2, int number);
    void selection();
    void tourney_selection();
    void mutate();
    void updatePopulation();
    double getHighestGrade();
    Specimen getBestSpec();
    std::vector <Cooridinates> &getBestSpecRabbitPositions();
    void printRabbitPostions();


private:
    int size;
    std::vector <Specimen> specimens;
    double highestGrade;
    Specimen bestSpec;
    std::vector <Cooridinates> bestSpecRabbitPositions;
};

#endif // POPULATION_H
