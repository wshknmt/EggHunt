#include "QtBoard.h"
#include "ui_QtBoard.h"
#include<QDebug>
QtBoard::QtBoard(std::vector <Cooridinates> rabbitPositions, Specimen bestSpecimen, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtBoard)
{
    ui->setupUi(this);
    ui->resetButton->setEnabled(false);
    this->rabbitPositions = rabbitPositions;
    this->bestSpecimen = bestSpecimen;
    ui->eggsLabel->setText(QString(QString::number(bestSpecimen.getCollectedEggs())));
    ui->gradeLabel->setText(QString(QString::number(bestSpecimen.getGrade())));
    reset = false;
    fieldIsEgg = false;
    eggTaken = -1;

    //int side = 7;


    int shift = (width()-80)/SIDE;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    egg = QImage(":/new/images/egg.jpg");
    wall = QImage(":/new/images/wall.jpg");
    rabbit = QImage(":/new/images/rabbit.jpg");
    grass = QImage(":/new/images/grass.jpeg");
    egg = egg.scaled(QSize(shift, shift));
    wall = wall.scaled(QSize(shift, shift));
    rabbit = rabbit.scaled(QSize(shift, shift));
    grass = grass.scaled(QSize(shift, shift));

    //QBrush redBrush(Qt::red);
   // QBrush blueBrush(Qt::blue);

   // QPen blackPen(Qt::black);
   // blackPen.setWidth(6);
    QBrush image;
    image.setTextureImage(grass);
    for(int i =0; i<SIDE; i++) {
        std::vector <QGraphicsRectItem*> rectV;
        for(int j = 0; j < SIDE; j++) {
            QGraphicsRectItem *newRect;
            newRect = scene->addRect(i*shift, j*shift, shift, shift);
            FieldType type = Board::getInstance()->getFields()[j][i].getType();
            if(type == FieldType::WALL) image.setTextureImage(wall);
            else if(type == FieldType::EGG) image.setTextureImage(egg);
            else if(type == FieldType::EMPTY) image.setTextureImage(grass);
            newRect->setBrush(image);
            rectV.push_back(newRect);
        }
        qtBoard.push_back(rectV);
    }
    setRectRabbitImage(rabbitPositions[0]);

}

void QtBoard::setRectEggImage(Cooridinates c) {
    QBrush image;
    image.setTextureImage(egg);
    qtBoard[c.first][c.second]->setBrush(image);
}
void QtBoard::setRectWallImage(Cooridinates c) {
    QBrush image;
    image.setTextureImage(wall);
    qtBoard[c.first][c.second]->setBrush(image);
}
void QtBoard::setRectRabbitImage(Cooridinates c) {
    QBrush image;
    image.setTextureImage(rabbit);
    qtBoard[c.first][c.second]->setBrush(image);
}
void QtBoard::setRectGrassImage(Cooridinates c) {
    QBrush image;
    image.setTextureImage(grass);
    qtBoard[c.first][c.second]->setBrush(image);
}

QtBoard::~QtBoard() {
    delete ui;
}

void QtBoard::on_startButton_clicked() {
    ui->startButton->setEnabled(false);
    ui->resetButton->setEnabled(true);
    Cooridinates prev = rabbitPositions[0];
    for(int i = 1; i < rabbitPositions.size(); i++) {
        if(reset) break;
        setRectGrassImage(prev);
        setRectRabbitImage(rabbitPositions[i]);
        ui->moveLabel->setText(QString(QString::fromStdString(bestSpecimen.getMovesVector()[i-1].getMoveName())));
        prev = rabbitPositions[i];
        delay(1);

    }
    reset = false;

}

void QtBoard::delay(int seconds) {
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void QtBoard::on_exitButton_clicked() {
    QCoreApplication::quit();
}
void QtBoard::resetBoard() {
    for(int i =0; i<SIDE; i++) {
        //std::vector <QGraphicsRectItem*> rectV;
        for(int j = 0; j < SIDE; j++) {
           // QGraphicsRectItem *newRect;
           // newRect = scene->addRect(i*shift, j*shift, shift, shift);
            FieldType type = Board::getInstance()->getFields()[j][i].getType();
            if(type == FieldType::WALL) setRectWallImage(Cooridinates(i, j));
            else if(type == FieldType::EGG) setRectEggImage(Cooridinates(i, j));
            else if(type == FieldType::EMPTY) setRectGrassImage(Cooridinates(i, j));
        }
        //qtBoard.push_back(rectV);
    }
    setRectRabbitImage(rabbitPositions[0]);
}

void QtBoard::on_resetButton_clicked() {
    reset = true;

    ui->startButton->setEnabled(true);
    ui->resetButton->setEnabled(false);
    delay(1);
    resetBoard();
}
