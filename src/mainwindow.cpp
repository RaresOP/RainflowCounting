#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <fstream>
#include <algorithm>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(bool firstTime)
{
    auto numberOfValues=m_yVec.size();
    QVector<double> xAxis(numberOfValues);
    std::iota(xAxis.begin(),xAxis.end(),0);
    if(!firstTime)
        ui->customPlot->removeGraph(0);
    ui->customPlot->addGraph(0);

    ui->customPlot->graph(0)->setData(xAxis, QVector<double>::fromStdVector(m_yVec));
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, xAxis.size());
    ui->customPlot->yAxis->setRange(*(std::min_element(m_yVec.begin(),m_yVec.end()))-2,  *(std::max_element(m_yVec.begin(),m_yVec.end()))+2);

    ui->customPlot->replot();
}



void MainWindow::on_Btn_loadFile_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,tr("Open file"),"/home","All files(*.*);;Text file(*.txt)"
                );
    std::ifstream ifs (filename.toStdString(), std::ifstream::in);
    std::istream_iterator<double> input(ifs);
    std::copy(input, std::istream_iterator<double>(), std::back_inserter(m_yVec));
    m_rfCounter.KeepPeaksAndValleys(m_yVec);
    makePlot();

}

void MainWindow::on_btn_cycle_clicked()
{
    m_rfCounter.RemoveNextCycle(m_yVec);
    makePlot(false);

}



