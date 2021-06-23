#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include "Specimen.h"
#include "Board.h"
#include <algorithm>
class Population
{
public:
    Population();
    Population(int size, int specimenLength, int side, int startX, int startY);
    void print();
    void singleCrossover(int crossoverProbability);
    void crossover(std::vector <Move>& mV1, std::vector <Move>& mV2, int number);
    void selection();
    void tourney_selection();
    void mutate(int mutationProbability);
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
    int specimenLength;
};

#endif // POPULATION_H
