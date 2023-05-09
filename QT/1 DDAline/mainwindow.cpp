#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMouseEvent>
#include<iostream>
using namespace std;

QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::ddaline(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    float dx = x2-x1;
    float dy = y2-y1;
    int step = max(abs(dx),abs(dy));
    float xinc = dx/step;
    float yinc = dy/step;
    int i = 0;
    while(i<step){
        img.setPixel(x,y,qRgb(255,255,255));
        x += xinc;
        y += yinc;
        i++;
    }

}

