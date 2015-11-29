#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gasimulator.h"
#include "parameters.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GASimulator simulator;
    SimulationParameters readSimulationParameters();
    void populateComboBoxes();
    void adjustRelatedWidgetsForIterationCount();
    void adjustRelatedWidgetsForChromosomeMajority();
    void adjustRelatedWidgetsForMutationNone();
    void adjustRelatedWidgetsForMutationRandom();
    void adjustRelatedWidgetsForMutationChosen();
    void setTextEditValidators();


private slots:
    void on_pushButtonStart_clicked();
    void on_CBMutationType_currentIndexChanged(const QString & chosen);
    void on_sliderMutation_valueChanged(int value);
    void on_CBFinishCondition_currentIndexChanged(const QString &chosen);
    void on_sliderFinishCondition_valueChanged(int value);
    void on_sliderElitism_valueChanged(int value);
    void on_txtElitism_textChanged(const QString &text);
    void on_txtFinishCondition_textChanged(const QString &text);
    void on_txtMutation_textChanged(const QString &text);
    void on_sliderMutationBit_valueChanged(int value);
    void on_txtMutationBitNumber_textChanged(const QString &text);
    void on_sliderPopulationSize_valueChanged(int value);
    void on_sliderBitCount_valueChanged(int value);
    void on_txtPopulationSize_textChanged(const QString &text);
    void on_txtBitCount_textChanged(const QString &text);
};

#endif // MAINWINDOW_H
