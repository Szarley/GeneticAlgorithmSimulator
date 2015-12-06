#ifndef PARAMSDIALOG_H
#define PARAMSDIALOG_H

#include <QDialog>
#include "enumparser.h"
#include "enumtypes.h"
#include "parameters.h"

namespace Ui{
class ParamsDialog;
}

class ParamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParamsDialog(SimulationParameters _params, QWidget *parent = 0);
    ~ParamsDialog();
signals:
    void parametersSet(SimulationParameters);

private:
    SimulationParameters params;
    Ui::ParamsDialog *ui;
    void populateComboBoxes();
    void adjustRelatedWidgetsForIterationCount();
    void adjustRelatedWidgetsForChromosomeMajority();
    void adjustRelatedWidgetsForMutationNone();
    void adjustRelatedWidgetsForMutationRandom();
    void adjustRelatedWidgetsForMutationChosen();
    void setTextEditValidators();
    void setParametersToWidgets();
    void getParametersFromWidgets();


private slots:
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
    void on_buttonBox_accepted();
};

#endif // PARAMSDIALOG_H

