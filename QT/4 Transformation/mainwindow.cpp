#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<QMouseEvent>
#include<vector> // storing the mouse click event;
#include<math.h>
using namespace std;

// storage for co-ordinates
vector<int>xco;
vector<int>yco;
int clicks = 0;
bool start;

QImage img (600,600,QImage::Format_RGB888); // very important line

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    showAxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    vector<int>xTrans;
    vector<int>yTrans;
    float theta = ui->textEdit->toPlainText().toFloat();
    theta = theta * 3.14 / 180;
    for (int i = 0; i< clicks; i++){
        int x = xco[i]-300;
        int y = yco[i]-300;
        xTrans.push_back(x*cos(theta) -y*sin(theta));
        yTrans.push_back(x*sin(theta) +y*cos(theta));
    }
    int n = clicks;
    for (int i = 0;i<n; i++){
        ddaLine(xTrans[i%n]+300,yTrans[i%n]+300,xTrans[(i+1)%n]+300,yTrans[(i+1)%n]+300);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ddaLine(int x1, int y1, int x2, int y2)
{
    float dx,dy,xinc,yinc,x,y,step;
    dx = x2-x1;
    dy = y2-y1;
    step = max(abs(x2-x1),abs(y2-y1));
    xinc = dx/step; yinc = dy/step;
    x = x1; y = y1;
    int i = 0;
    while(i<step){
        img.setPixel(x,y,qRgb(0,255,255));
        x = x+xinc;
        y = y+yinc;
        i++;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    cout<<clicks<<endl;

    int xClick = ev->pos().x();
    int yClick = ev->pos().y();
    //cout<<xClick<<" "<<yClick<<endl;
    if(xClick>600 || yClick >600) return;
    if(start){
        if(ev->button() == Qt::RightButton){
            ddaLine(xco[clicks-1],yco[clicks-1],xco[0],yco[0]);
            start = false;
            return;
        }
        else if(clicks == 0){
            xco.push_back(xClick);
            yco.push_back(yClick);
            clicks++;
        }
        else{
            xco.push_back(xClick);
            yco.push_back(yClick);
            ddaLine(xco[clicks],yco[clicks],xco[clicks-1],yco[clicks-1]);
            clicks++;
        }
        for (auto it : xco) cout<<it<<" ";
        cout<<endl;
    }
    ui->label->setPixmap(QPixmap::fromImage(img)); // this line plays and important role
}

void MainWindow::showAxes()
{
    ddaLine(300,50,300,550);
    ddaLine(50,300,550,300);
}


void MainWindow::on_pushButton_2_clicked()
{
    // scale
    vector<int>xTrans;
    vector<int>yTrans;
    float scale = ui->textEdit_3->toPlainText().toFloat();
    for (auto it : xco) xTrans.push_back((it-300)*scale*1ll);
    for (auto it : yco) yTrans.push_back((it-300)*scale*1ll);
    int n = xTrans.size();
    for (int i = 0;i<n; i++){
        ddaLine(xTrans[i%n]+300,yTrans[i%n]+300,xTrans[(i+1)%n]+300,yTrans[(i+1)%n]+300);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_3_clicked()
{
    // translate
    vector<int>xTrans;
    vector<int>yTrans;
    int xi = ui->textEdit_2->toPlainText().toInt();
    int yi = ui->textEdit_4->toPlainText().toInt();
    for (auto it : xco) xTrans.push_back(it+xi);
    for (auto it : yco) yTrans.push_back(it+yi);
    int n = xTrans.size();
    for (int i = 0;i<n; i++){
        ddaLine(xTrans[i%n],yTrans[i%n],xTrans[(i+1)%n],yTrans[(i+1)%n]);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


