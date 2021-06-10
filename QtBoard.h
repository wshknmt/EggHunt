#ifndef QTBOARD_H
#define QTBOARD_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <vector>
#include "Board.h"
#include "Field.h"
#include "FieldType.h"
#include "Specimen.h"

namespace Ui {
class QtBoard;
}

class QtBoard : public QDialog
{
    Q_OBJECT

public:
    explicit QtBoard(std::vector <Cooridinates> rabbitPositions, Specimen bestSpecimen, QWidget *parent = nullptr);
    ~QtBoard();
    void setRectEggImage(Cooridinates c);
    void setRectWallImage(Cooridinates c);
    void setRectRabbitImage(Cooridinates c);
    void setRectGrassImage(Cooridinates c);
    void delay(int seconds);
    void resetBoard();

private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::QtBoard *ui;
    QGraphicsScene *scene;
    //QGraphicsEllipseItem *ellipse;

    QGraphicsRectItem *rectangle;

    std::vector <std::vector <QGraphicsRectItem*> > qtBoard;
    std::vector <Cooridinates> rabbitPositions;
    Specimen bestSpecimen;

    QImage egg;
    QImage wall;
    QImage rabbit;
    QImage grass;

    bool reset;
    bool fieldIsEgg;
    int eggTaken;

};

#endif // QTBOARD_H
