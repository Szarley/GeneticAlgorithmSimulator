#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include "gasimulator.h"
#include "parameters.h"
#include "qcustomplot.h"
#include "paramsdialog.h"
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
    void setParamatersLabels();
    QString formatLabel(const QString description,const QString value) const;

public slots:
    void getParametersFromDialog(SimulationParameters params);
private slots:
    void on_pushButtonStart_clicked();

    void on_btnParamsSettings_clicked();
};

#endif // MAINWINDOW_H
