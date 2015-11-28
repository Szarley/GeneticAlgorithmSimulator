#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enumparser.h"
#include <QString>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    simulator()
{
    ui->setupUi(this);
    populateComboBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

SimulationParameters MainWindow::readSimulationParameters()
{
    SimulationParameters params;
    return params;
}

void MainWindow::on_pushButtonStart_clicked()
{
    simulator.setParameters(readSimulationParameters());
}

void MainWindow::populateComboBoxes()
{
  ui->CBMutationType->addItems(EnumParser<MutationType>::instance().getValues());
  ui->CBFinishCondition->addItems(EnumParser<FinishCondition>::instance().getValues());
}

void MainWindow::on_sliderMutation_valueChanged(int value)
{
    ui->txtMutation->setText(QString::number(value));
}

void MainWindow::on_CBMutationType_currentIndexChanged(const QString &chosen)
{

    if (chosen == EnumParser<MutationType>::instance().parse(MutationType::None))
    {
        adjustRelatedWidgetsForMutationNone();
    }
    else if (chosen == EnumParser<MutationType>::instance().parse(MutationType::ChosenBit))
    {
        adjustRelatedWidgetsForMutationChosen();
    }
    else if (chosen == EnumParser<MutationType>::instance().parse(MutationType::RandomBit))
    {
        adjustRelatedWidgetsForMutationRandom();
    }

}

void MainWindow::on_CBFinishCondition_currentIndexChanged(const QString &chosen)
{
    if(chosen == EnumParser<FinishCondition>::instance().parse(FinishCondition::ChromosomeMajority))
    {
        adjustRelatedWidgetsForIterationCount();
    }
    else if(chosen == EnumParser<FinishCondition>::instance().parse(FinishCondition::IterationCount))
    {
        adjustRelatedWidgetsForChromosomeMajority();
    }
}

void MainWindow::adjustRelatedWidgetsForIterationCount()
{
    ui->sliderFinishCondition->setRange(1,10000);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("0");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionIteration);
}

void MainWindow::adjustRelatedWidgetsForChromosomeMajority()
{
    ui->sliderFinishCondition->setRange(1,100);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("0");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionChrMajority);
}

void MainWindow::adjustRelatedWidgetsForMutationNone()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(false);
    ui->txtMutation->setEnabled(false);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("none");
}

void MainWindow::adjustRelatedWidgetsForMutationRandom()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("rand");
}

void MainWindow::adjustRelatedWidgetsForMutationChosen()
{
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(true);
    ui->txtMutationBitNumber->setText("0");
}

void MainWindow::on_sliderFinishCondition_valueChanged(int value)
{
    ui->txtFinishCondition->setText(QString::number(value));
}
