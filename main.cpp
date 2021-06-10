#include "MainWindow.h"
#include "QtBoard.h"

#include <QApplication>

#include <iostream>
#include <ctime>
#include "Population.h"
#include "Board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
   // w.show();










    srand(time(NULL));
    int generations = 100;
    std::cout << "start" << std::endl;

    Board::getInstance();
    Board::getInstance()->setRandom();
    Board::getInstance()->print();

    Population population(20, 40, SIDE);
    population.print();
    //population.singasdleCrossover();
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
    std::cout << "Best specimen rabbit positions: " << std::endl << std::endl;
    population.getBestSpec().printRabbitPostions();
    std::cout << "Collected eggs: " << population.getBestSpec().getCollectedEggs() << std::endl;
    std::cout << "Action counter: " << population.getBestSpec().getActionCounter() << std::endl;








    QtBoard b(population.getBestSpecRabbitPositions(), population.getBestSpec());
    b.exec();
    return a.exec();
}
