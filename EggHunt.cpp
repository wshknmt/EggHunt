// EggHunt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Population.h"
#include "Board.h"

int main() {
    srand(time(NULL));
    int side = 5;
    int generations = 200;
    std::cout << "start" << std::endl;
    Board board(side, 6);
    board.setRandom();
    board.print();
    Population population(16, 8, side, board);
    population.print();
    //population.singleCrossover();
    //std::cout << "po krzyzowaniu" << std::endl;
    population.print();
    Population popAfterSelection;
    int q = 0;
    std::cout << "START: " << std::endl<<std::endl;
    while (q < generations) {
        popAfterSelection = population.selection();
        popAfterSelection.singleCrossover();
        popAfterSelection.updatePopulation();
        popAfterSelection.mutate();
        popAfterSelection.updatePopulation();
        population = popAfterSelection;
        std::cout << "highest grade: " << population.getHighestGrade() << std::endl;
        q++;
    }

    std::cout << "Board: " <<std::endl << std::endl;
    board.print();
    std::cout << "Best specimen: " << std::endl << std::endl;
    population.getBestSpec().print();
    
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
