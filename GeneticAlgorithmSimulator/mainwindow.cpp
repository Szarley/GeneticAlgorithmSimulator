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
    setTextEditValidators();
}

MainWindow::~MainWindow()
{
    delete ui;
}

SimulationParameters MainWindow::readSimulationParameters()
{
    SimulationParameters params;
    params.finishCondition = EnumParser<FinishCondition>::instance().toEnum(ui->CBFinishCondition->currentText());
    params.selectionType = EnumParser<SelectionType>::instance().toEnum(ui->CBSelectionType->currentText());
    params.mutationType = EnumParser<MutationType>::instance().toEnum(ui->CBMutationType->currentText());
    params.elitismCoefficient = ui->sliderElitism->value();
    params.mutationCoefficient = ui->sliderMutation->value();
    if(params.finishCondition == FinishCondition::IterationCount)
    {
        params.iterationCount = ui->sliderFinishCondition->value();
       // params.chromosomeMajority = 0;
    }
    else
    {
        //params.chromosomeMajority = ui->sliderFinishCondition->value() / 100.0;
        params.iterationCount = 0;
    }
    return params;
}

void MainWindow::on_pushButtonStart_clicked()
{
    simulator.setParameters(readSimulationParameters());
    int x;
}

void MainWindow::populateComboBoxes()
{
  ui->CBMutationType->addItems(EnumParser<MutationType>::instance().getValues());
  ui->CBFinishCondition->addItems(EnumParser<FinishCondition>::instance().getValues());
  ui->CBSelectionType->addItems(EnumParser<SelectionType>::instance().getValues());
}

void MainWindow::on_sliderMutation_valueChanged(int value)
{
    ui->txtMutation->setText(QString::number(value));
}

void MainWindow::on_CBMutationType_currentIndexChanged(const QString &chosen)
{
    switch(EnumParser<MutationType>::instance().toEnum(chosen))
    {
    case MutationType::None:
        adjustRelatedWidgetsForMutationNone();
        break;
    case MutationType::ChosenBit:
        adjustRelatedWidgetsForMutationChosen();
        break;
    case MutationType::RandomBit:
        adjustRelatedWidgetsForMutationRandom();
        break;
    }
}

void MainWindow::on_CBFinishCondition_currentIndexChanged(const QString &chosen)
{
    switch(EnumParser<FinishCondition>::instance().toEnum(chosen))
    {
    case FinishCondition::ChromosomeMajority:
        adjustRelatedWidgetsForChromosomeMajority();
        break;
    case FinishCondition::IterationCount:
        adjustRelatedWidgetsForIterationCount();
        break;
    }
}

void MainWindow::adjustRelatedWidgetsForIterationCount()
{
    ui->sliderFinishCondition->setRange(1,10000);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("1");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionIteration);
}

void MainWindow::adjustRelatedWidgetsForChromosomeMajority()
{
    ui->sliderFinishCondition->setRange(1,100);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("1");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionChrMajority);
}

void MainWindow::adjustRelatedWidgetsForMutationNone()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(false);
    ui->txtMutation->setEnabled(false);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("none");
    ui->sliderMutationBit->setValue(0);
    ui->sliderMutationBit->setEnabled(false);
}

void MainWindow::adjustRelatedWidgetsForMutationRandom()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("rand");
    ui->sliderMutationBit->setValue(0);
    ui->sliderMutationBit->setEnabled(false);
}

void MainWindow::adjustRelatedWidgetsForMutationChosen()
{
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(true);
    ui->txtMutationBitNumber->setText("0");
    ui->sliderMutationBit->setEnabled(true);
}

void MainWindow::on_sliderFinishCondition_valueChanged(int value)
{
    ui->txtFinishCondition->setText(QString::number(value));
}

void MainWindow::on_sliderElitism_valueChanged(int value)
{
    ui->txtElitism->setText(QString::number(value));
}

void MainWindow::setTextEditValidators()
{
    ui->txtElitism->setValidator(new QIntValidator(0,100,this));
    ui->txtMutation->setValidator(new QIntValidator(0,100,this));
    ui->txtFinishCondition->setValidator(new QIntValidator(0,100,this));
    ui->txtMutationBitNumber->setValidator(new QIntValidator(0,1,this));
    ui->txtPopulationSize->setValidator(new QIntValidator(1,1000,this));
    ui->txtBitCount->setValidator(new QIntValidator(1,20,this));
}

void MainWindow::on_txtElitism_textChanged(const QString &text)
{
    ui->sliderElitism->setValue(text.toInt());
}

void MainWindow::on_txtFinishCondition_textChanged(const QString &text)
{
    ui->sliderFinishCondition->setValue(text.toInt());
}

void MainWindow::on_txtMutation_textChanged(const QString &text)
{
    ui->sliderMutation->setValue(text.toInt());
}

void MainWindow::on_sliderMutationBit_valueChanged(int value)
{
    ui->txtMutationBitNumber->setText(QString::number(value));
}

void MainWindow::on_txtMutationBitNumber_textChanged(const QString &text)
{
    ui->sliderMutationBit->setValue(text.toInt());
}

void MainWindow::on_sliderPopulationSize_valueChanged(int value)
{
    ui->txtPopulationSize->setText(QString::number(value));
}

void MainWindow::on_sliderBitCount_valueChanged(int value)
{
    ui->txtBitCount->setText(QString::number(value));
    ui->txtMutationBitNumber->setValidator(new QIntValidator(0,value - 1,this));
    ui->sliderMutationBit->setRange(0, value - 1);
}

void MainWindow::on_txtPopulationSize_textChanged(const QString &text)
{
    ui->sliderPopulationSize->setValue(text.toInt());
}

void MainWindow::on_txtBitCount_textChanged(const QString &text)
{
    ui->sliderBitCount->setValue(text.toInt());
}
