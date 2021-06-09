// EggHunt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Population.h"
#include "Board.h"

int main() {
    srand(time(NULL));
    int generations = 100;
    std::cout << "start" << std::endl;

    Board::getInstance();
    Board::getInstance()->setRandom();
    Board::getInstance()->print();

    Population population(20, 15, SIDE);
    population.print();
    //population.singleCrossover();
    //std::cout << "po krzyzowaniu" << std::endl;
    population.print();
    Population popAfterSelection;
    int q = 0;
    std::cout << "START: " << std::endl<<std::endl;
    while (q < generations) {

        population.tourney_selection();
       //population.selection();
        population.singleCrossover();
        population.updatePopulation();
        population.mutate();
        population.updatePopulation();

        std::cout << "highest grade: " << (float)population.getHighestGrade() << std::endl;
       // population.print();
        /*std::cout << "Best specimen: " << std::endl << std::endl;
        population.getBestSpec().print();*/
        q++;
    }

    std::cout << "Board: " <<std::endl << std::endl;
    Board::getInstance()->print();
    std::cout << "Best specimen: " << std::endl << std::endl;
    population.getBestSpec().print();
    std::cout << "Collected eggs: " << population.getBestSpec().getCollectedEggs() << std::endl;
    std::cout << "Action counter: " << population.getBestSpec().getActionCounter() << std::endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
