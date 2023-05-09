#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <vector>
#include <iostream>
using namespace std;

// mouse event
vector<int>X;
vector<int>Y;
bool start = false;
int click = -1;

// clipping essentials
int i,t,b, r, l,xmax, ymax, xmin,ymin;


QImage img(600,600,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    i = 0; t = 8; b = 4; r = 2; l = 1;
    xmax = 400, xmin = 200; ymax = 400; ymin = 200;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ddaLine(200,200,400,200,0);
    ddaLine(400,200,400,400,0);
    ddaLine(400,400,200,400,0);
    ddaLine(200,400,200,200,0);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ddaLine(int x1, int y1, int x2, int y2,int col = 255)
{
    float dx,dy,xinc,yinc,x,y,step;
    dx = x2-x1;
    dy = y2-y1;
    step = max(abs(dx),abs(dy));
    int i = 0;
    xinc = dx/step;
    yinc = dy/step;
    x = x1;
    y = y1;
    while(i<step){
        img.setPixel(x,y,qRgb(0,col,255));
        x = x+xinc;
        y = y+yinc;
        i++;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int x = ev->pos().x();
    int y = ev->pos().y();
    cout<<x<<" "<<y<<" "<<click<<endl;

    if(start){
        X.push_back(x);
        Y.push_back(y);
        click++;
        if(click%2 ==1){
            ddaLine(X[click],Y[click],X[click-1],Y[click-1]);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::getCode(int x, int y)
{
    int code = 0;
    if(x<xmin) code |= l;
    if(x>xmax) code |= r;
    if(y>ymax) code |= t;
    if(y<ymin) code |= b;
    return code;
}

bool MainWindow::clipLine(int x1, int y1, int x2, int y2)
{
    int code1 = getCode(x1,y1);
    int code2 = getCode(x2,y2);
    bool inside = false;

    while(true){
        if(code1 ==0 && code2 ==0){
            inside = true;
            break;
        }
        else if (code1 & code2){
            break;
        }
        else{
            int codeOut;
            int x,y;
            if(code1!=0) codeOut = code1;
            else codeOut = code2;

            // finding the region of codout
            if(codeOut & t){
                // in top region
                x=(x1-x2)*(ymax-y2)/(y1-y2)+x2;
                y=ymax;
            }
            else if (codeOut & b){
                // in bottom region
                x=(x1-x2)*(ymin-y2)/(y1-y2)+x2;
                y=ymin;
            }
            else if (codeOut & r){
                // in right region
                x=xmax;
                y=(y1-y2)*(xmax-x2)/(x1-x2)+y2;
            }
            else if(codeOut & l){
                // in left region
                x=xmin;
                y=(y1-y2)*(xmin-x2)/(x1-x2)+y2;
            }

            // updating the change cordinate
            if(codeOut == code1){
                x1 = x; y1 = y;
                code1 = getCode(x1,y1);
            }
            else if (codeOut == code2){
                x2 = x; y2 = y;
                code2 = getCode(x2,y2);
            }
        }

    }
    if(inside){
        ddaLine(x1,y1,x2,y2,0);
    }
    return inside;

}

void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < 600; ++i) {
        for (int j = 0; j < 600; ++j) {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ddaLine(200,200,400,200,0);
    ddaLine(400,200,400,400,0);
    ddaLine(400,400,200,400,0);
    ddaLine(200,400,200,200,0);
    for (int i = 0; i<X.size(); i+=2){
        clipLine(X[i],Y[i],X[i+1],Y[i+1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

