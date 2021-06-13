#include "QtBoard.h"

#include <QApplication>

#include <iostream>
#include <ctime>
#include "Population.h"
#include "Board.h"
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::fstream file;
    file.open("../EggHunt/logs.txt", std::ios::app);
    if (!file.good()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }
    clock_t start = clock();
    srand(time(NULL)); //100
    int generations = 10000;
    int populationSize = 100;
    int specimenLength = 50;
    int crossoverProbability = 20;
    int mutationProbability = 100;
    Board::getInstance()->setRandom();
    Board::getInstance()->print();

    Population population(populationSize, specimenLength, SIDE);
    population.print();
    file << "Generations: " << generations << "\nPopulation size: " << populationSize << "\nSpecimen length: " << specimenLength << "\nBoard side: " << SIDE << "\nMutation probability: " <<
            mutationProbability << "\nCrossover probability: " << crossoverProbability << "\n";
    int q = 0;
    while (q < generations && (clock() - start) / (float)CLOCKS_PER_SEC < 60) {

        population.tourney_selection();
        population.singleCrossover(crossoverProbability);
        population.updatePopulation();
        population.mutate(mutationProbability);
        population.updatePopulation();
        std::cout << "highest grade: " << (float)population.getHighestGrade() << std::endl;
        if (q % (generations / 10) == 0) {
            file << "Population " << q << ", highest grade: " << (float)population.getHighestGrade() << "\n";
        }
        q++;
    }
    std::cout << "Board: " << std::endl;
    Board::getInstance()->print();
    std::cout << "Best specimen: " << std::endl;
    population.getBestSpec().print();
    file << "Best specimen: " << population.getBestSpec().toString() << "\n";
    std::cout << "Collected eggs: " << population.getBestSpec().getCollectedEggs() << std::endl;
    std::cout << "Action counter: " << population.getBestSpec().getActionCounter() << std::endl;
    file << "Collected eggs: " << population.getBestSpec().getCollectedEggs() << "/" << EGGS_AMOUNT << "\nAction counter: " << population.getBestSpec().getActionCounter() << "\n";
    float time = (clock() - start) / (float)CLOCKS_PER_SEC;//1000000.000;
    file << "Generations: " << q << "\n";
    file << "Time: " << time << "s\n\n";
    file.close();
    QtBoard b(population.getBestSpecRabbitPositions(), population.getBestSpec());
    b.setWindowTitle("EggHunt");
    b.setWindowIcon(QIcon(":/new/images/rabbit.jpg"));
    b.show();
    return a.exec();
}
