#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mousePressEvent (QMouseEvent* ev);
    void ddaLine (int ,int , int , int);
    void scanLine ();
    void mouseDoubleClickEvent(QMouseEvent* ev);
    void delay(int millisecondsToWait);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
