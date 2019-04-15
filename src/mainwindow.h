#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <qvector.h>
#include <memory>
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
    void KeepPeaksAndValleys();
    void on_btn_cycle_clicked();

private:
    Ui::MainWindow               *ui;
    QVector<double>              m_yVec;




};

#endif // MAINWINDOW_H
