#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <qvector.h>
#include <memory>
#include "rainflowcounter.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void makePlot(bool firstTime=true);
    void on_Btn_loadFile_clicked();
    void on_btn_cycle_clicked();

private:
    Ui::MainWindow               *ui;
    std::vector<double>          m_yVec;
    RainflowCounter              m_rfCounter;




};

#endif // MAINWINDOW_H
