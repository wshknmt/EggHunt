#include "Population.h"

Population::Population(int populationSize, int specimenLength, int side) {
	this->size = populationSize;
    highestGrade = -1.0;

	for (int i = 0; i < size; i++) {
		Specimen specimen(specimenLength, side);
		specimens.push_back(specimen);
	}
    bestSpec = specimens[0];
}

Population::Population() {

}

void Population::print() {
    std::cout << std::endl << "Population: " << std::endl;
	for (int i = 0; i < size; i++) {
		specimens[i].print();
	}
}

void Population::singleCrossover() {
    int number = specimens.size() / 2;
    for (int i = 0; i < (specimens.size() / 2); i++) {
        if (rand() % 100 < 100) //crossoverProbability
            crossover(specimens[2 * i].getMovesVector(), specimens[2 * i + 1].getMovesVector(), number);

    }
}


void Population::crossover(std::vector <Move> & mV1, std::vector <Move> & mV2, int number)
{
    std::vector <Move> temp;
    temp.insert(temp.end(), mV1.begin(), mV1.begin() + number);
    std::reverse(mV1.begin(), mV1.end());
    for (int i = 0; i < number; i++)   
        mV1.pop_back();   
    std::reverse(mV1.begin(), mV1.end());
    mV1.insert(mV1.begin(), mV2.begin(), mV2.begin() + number);
    std::reverse(mV2.begin(), mV2.end());
    for (int i = 0; i < number; i++)    
        mV2.pop_back();
    std::reverse(mV2.begin(), mV2.end());
    mV2.insert(mV2.begin(), temp.begin(), temp.begin() + number);
}

Population Population::selection() {
    Population pop;
    int temp;
    for (unsigned int i = 0; i < specimens.size(); i++) {
        temp = rand() % specimens.size();
        pop.specimens.push_back(specimens[temp]);
    }
    return pop;
}
void Population::mutate() {
    for (unsigned int i = 0; i < specimens.size(); i++) {
        specimens[i].mutate(50);
    }
}

void Population::updatePopulation() {
    for (unsigned int i = 0; i < specimens.size(); i++) {
        specimens[i].calculateGrade();
        if (specimens[i].getGrade() > highestGrade) {
            highestGrade = specimens[i].getGrade();
            bestSpec = specimens[i];
        }
            
    }
}

double Population::getHighestGrade() {
    return highestGrade;
}

Specimen Population::getBestSpec() {
    return bestSpec;
}
