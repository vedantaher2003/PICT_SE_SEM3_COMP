#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <iostream>
#include <vector>
#include <algorithm>
#include<QTime>
#include<QtDebug>
using namespace std;

// mouse click event
vector<int>X;
vector<int>Y;
int cl = -1;
bool start;

QImage img (600,600,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int x = ev->pos().x();
    int y = ev->pos().y();

    if(start == true){
        if(ev->button() == Qt::RightButton){
            ddaLine(X[0],Y[0],X[cl],Y[cl]);
            start = false;
            //scanLine();
            return;
        }
        else if (cl == -1){
            cl++;
            X.push_back(x);
            Y.push_back(y);
        }
        else{
            cl++;
            X.push_back(x);
            Y.push_back(y);
            ddaLine(X[cl],Y[cl],X[cl-1],Y[cl-1]);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::ddaLine(int x1, int y1 , int x2, int y2)
{
    float dx,dy,xinc,yinc,x,y,step;
    x = x1; y = y1;
    dx = x2-x1;
    dy = y2-y1;
    step = max(abs(dx),abs(dy));
    xinc = dx/step;
    yinc = dy/step;
    int i = 0;
    while(i<step){
        img.setPixel(x,y,qRgb(0,0,255));
        x = x+xinc;
        y = y+yinc;
        i++;
    }
    return;
}

void MainWindow::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::scanLine()
{
    vector<float>slopes;
    int ymin = 700, ymax = -1;
    int n = Y.size();
    for (auto it : X) cout<<it<<" ";
    cout<<endl;
    for (auto it : Y) cout<<it<<" ";
    cout<<endl;
    // finding the minimum and maximum Y
    for (int i = 0; i<n; i++){
        if(Y[i]>ymax) ymax = Y[i];
        if(Y[i]<ymin) ymin = Y[i];
    }
    cout<<ymax<<" "<<ymin<<endl;
    for (int i = 0; i<n; i++){
        float dx = X[(i+1)%n]-X[i%n];
        float dy = Y[(i+1)%n]-Y[i%n];
        if(dx ==0) slopes.push_back(0);
        else if (dy ==0) slopes.push_back(1);
        else slopes.push_back(dx*1ll/dy);
    }
  //   filling with finding the points for x
    for (int i = ymin; i< ymax ; i++){
        vector<int>Xfilling;

        // finding the points
        for (int j = 0; j<n; j++){
            if((i>=Y[j%n] && i< Y[(j+1)%n])||(i>=Y[(j+1)%n] && i<Y[j%n])){
                int pt = X[j] +(slopes[(j)%n]*(i-Y[j])*1ll);
                Xfilling.push_back(pt);
            }
        }
        sort(Xfilling.begin(),Xfilling.end());

        int m = Xfilling.size();

        for(int k = 0; k<m; k+=2){
            ddaLine(Xfilling[k%m],i,Xfilling[(k+1)%m],i);
            delay(5);
        }
    }

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    scanLine();
    ui->label->setPixmap(QPixmap::fromImage(img));
}



