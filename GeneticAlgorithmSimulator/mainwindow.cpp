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
    setParamatersLabels();
    ui->btnParamsSettings->setIcon(QIcon(QPixmap("/home/szarley/Projects/GA/GeneticAlgorithmSimulator/assets/klucz_ikona.ico")));
    ui->btnParamsSettings->setIconSize(QSize(20, 20));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{

}
void MainWindow::getParametersFromDialog(SimulationParameters params)
{
    simulator.setParameters(params);
    setParamatersLabels();
}

void MainWindow::setParamatersLabels()
{
    ui->lblPopulation->setText(formatLabel("Population size: ", QString::number(simulator.getParameters().populationSize)));
    ui->lblBitCount->setText(formatLabel("Bit count: ", QString::number(simulator.getParameters().bitCount)));
    ui->lblFinishCond->setText(formatLabel("Finish condition: ",EnumParser<FinishCondition>::instance().
                                           toString(simulator.getParameters().finishCondition)));
    ui->lblMutationType->setText(formatLabel("Mutation type: ",EnumParser<MutationType>::instance().
                                             toString(simulator.getParameters().mutationType)));
    ui->lblSelectionType->setText(formatLabel("Selection type: ",EnumParser<SelectionType>::instance().
                                              toString(simulator.getParameters().selectionType)));
    ui->lblFinishCondCoeff->setText(formatLabel("Finish point: ",QString::number(simulator.getParameters().finishCoefficient)));
    ui->lblMutationCoeff->setText(formatLabel("Mutation coefficient: ",QString::number(simulator.getParameters().mutationCoefficient)));
    QString mutatedBit = simulator.getParameters().mutationType ==
            MutationType::ChosenBit ?
            QString::number(simulator.getParameters().mutationBit) :
            "random";
    ui->lblMutationBit->setText(formatLabel("Mutated bit: ", mutatedBit));
}
QString MainWindow::formatLabel(const QString description, const QString value) const
{
    return QString("<b>" + description  + " <font color=\"red\"> " +value + "</font></b>  ");
}

void MainWindow::on_btnParamsSettings_clicked()
{
    ParamsDialog *d = new ParamsDialog(simulator.getParameters(),this);
    d->setAttribute(Qt::WA_DeleteOnClose,true);
    d->exec();
}
