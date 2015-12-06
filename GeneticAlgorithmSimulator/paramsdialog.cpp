#include "paramsdialog.h"
#include "ui_paramsdialog.h"

ParamsDialog::ParamsDialog(SimulationParameters _params, QWidget *parent) :
    params(_params),
    QDialog(parent),
    ui(new Ui::ParamsDialog)
{
    ui->setupUi(this);
    populateComboBoxes();
    setTextEditValidators();
    setParametersToWidgets();
    connect(this, SIGNAL(parametersSet(SimulationParameters)),parent, SLOT(getParametersFromDialog(SimulationParameters)));
}

ParamsDialog::~ParamsDialog()
{
    delete ui;

}

void ParamsDialog::populateComboBoxes()
{
  ui->CBMutationType->addItems(EnumParser<MutationType>::instance().getValues());
  ui->CBFinishCondition->addItems(EnumParser<FinishCondition>::instance().getValues());
  ui->CBSelectionType->addItems(EnumParser<SelectionType>::instance().getValues());
}

void ParamsDialog::on_sliderMutation_valueChanged(int value)
{
    ui->txtMutation->setText(QString::number(value));
}

void ParamsDialog::on_CBMutationType_currentIndexChanged(const QString &chosen)
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

void ParamsDialog::on_CBFinishCondition_currentIndexChanged(const QString &chosen)
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

void ParamsDialog::adjustRelatedWidgetsForIterationCount()
{
    ui->sliderFinishCondition->setRange(1,10000);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("1");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionIteration);
}

void ParamsDialog::adjustRelatedWidgetsForChromosomeMajority()
{
    ui->sliderFinishCondition->setRange(1,100);
    ui->sliderFinishCondition->setValue(1);
    ui->txtFinishCondition->setText("1");
    ui->labelFinishConditionDescription->setText(UILabels::finishConditionChrMajority);
}

void ParamsDialog::adjustRelatedWidgetsForMutationNone()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(false);
    ui->txtMutation->setEnabled(false);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("none");
    ui->sliderMutationBit->setValue(0);
    ui->sliderMutationBit->setEnabled(false);
}

void ParamsDialog::adjustRelatedWidgetsForMutationRandom()
{
    ui->sliderMutation->setValue(0);
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(false);
    ui->txtMutationBitNumber->setText("rand");
    ui->sliderMutationBit->setValue(0);
    ui->sliderMutationBit->setEnabled(false);
}

void ParamsDialog::adjustRelatedWidgetsForMutationChosen()
{
    ui->sliderMutation->setEnabled(true);
    ui->txtMutation->setEnabled(true);
    ui->txtMutationBitNumber->setEnabled(true);
    ui->txtMutationBitNumber->setText("0");
    ui->sliderMutationBit->setEnabled(true);
}

void ParamsDialog::on_sliderFinishCondition_valueChanged(int value)
{
    ui->txtFinishCondition->setText(QString::number(value));
}

void ParamsDialog::on_sliderElitism_valueChanged(int value)
{
    ui->txtElitism->setText(QString::number(value));
}

void ParamsDialog::setTextEditValidators()
{
    ui->txtElitism->setValidator(new QIntValidator(0,100,this));
    ui->txtMutation->setValidator(new QIntValidator(0,100,this));
    ui->txtFinishCondition->setValidator(new QIntValidator(0,100,this));
    ui->txtMutationBitNumber->setValidator(new QIntValidator(0,1,this));
    ui->txtPopulationSize->setValidator(new QIntValidator(1,1000,this));
    ui->txtBitCount->setValidator(new QIntValidator(1,20,this));
}

void ParamsDialog::on_txtElitism_textChanged(const QString &text)
{
    ui->sliderElitism->setValue(text.toInt());
}

void ParamsDialog::on_txtFinishCondition_textChanged(const QString &text)
{
    ui->sliderFinishCondition->setValue(text.toInt());
}

void ParamsDialog::on_txtMutation_textChanged(const QString &text)
{
    ui->sliderMutation->setValue(text.toInt());
}

void ParamsDialog::on_sliderMutationBit_valueChanged(int value)
{
    ui->txtMutationBitNumber->setText(QString::number(value));
}

void ParamsDialog::on_txtMutationBitNumber_textChanged(const QString &text)
{
    ui->sliderMutationBit->setValue(text.toInt());
}

void ParamsDialog::on_sliderPopulationSize_valueChanged(int value)
{
    ui->txtPopulationSize->setText(QString::number(value));
}

void ParamsDialog::on_sliderBitCount_valueChanged(int value)
{
    ui->txtBitCount->setText(QString::number(value));
    ui->txtMutationBitNumber->setValidator(new QIntValidator(0,value - 1,this));
    ui->sliderMutationBit->setRange(0, value - 1);
}

void ParamsDialog::on_txtPopulationSize_textChanged(const QString &text)
{
    ui->sliderPopulationSize->setValue(text.toInt());
}

void ParamsDialog::on_txtBitCount_textChanged(const QString &text)
{
    ui->sliderBitCount->setValue(text.toInt());
}

void ParamsDialog::setParametersToWidgets()
{
    ui->sliderPopulationSize->setValue(params.populationSize);
    ui->sliderBitCount->setValue(params.bitCount);
    ui->sliderMutationBit->setValue(params.mutationBit);
    ui->sliderElitism->setValue(params.elitismCoefficient);
    ui->sliderMutation->setValue(params.mutationCoefficient);
    ui->sliderFinishCondition->setValue(params.finishCoefficient);

    int CBindex = ui->CBFinishCondition->findText(
                EnumParser<FinishCondition>::instance().toString(params.finishCondition));
    ui->CBFinishCondition->setCurrentIndex(CBindex);

    CBindex = ui->CBMutationType->findText(
                EnumParser<MutationType>::instance().toString(params.mutationType));
    ui->CBMutationType->setCurrentIndex(CBindex);

    CBindex = ui->CBSelectionType->findText(
                EnumParser<SelectionType>::instance().toString(params.selectionType));
    ui->CBSelectionType->setCurrentIndex(CBindex);
}

void ParamsDialog::getParametersFromWidgets()
{
    params.selectionType        = EnumParser<SelectionType>::instance().toEnum(ui->CBSelectionType->currentText());
    params.mutationType         = EnumParser<MutationType>::instance().toEnum(ui->CBMutationType->currentText());
    params.finishCondition      = EnumParser<FinishCondition>::instance().toEnum(ui->CBFinishCondition->currentText());
    params.finishCoefficient    = ui->sliderFinishCondition->value();
    params.populationSize       = ui->sliderPopulationSize->value();
    params.bitCount             = ui->sliderBitCount->value();
    params.mutationBit          = params.mutationType == MutationType::ChosenBit ? ui->sliderMutationBit->value() : 0;
    params.elitismCoefficient   = ui->sliderElitism->value();
    params.mutationCoefficient  = ui->sliderMutation->value();

}

void ParamsDialog::on_buttonBox_accepted()
{
    getParametersFromWidgets();
    emit parametersSet(params);
}
