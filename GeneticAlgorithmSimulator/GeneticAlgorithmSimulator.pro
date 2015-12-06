#-------------------------------------------------
#
# Project created by QtCreator 2015-11-20T20:31:52
#
#-------------------------------------------------

QT       += core gui\
            printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneticAlgorithmSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chromosome.cpp \
    uniformintgenerator.cpp \
    chromosomepopulation.cpp \
    gasimulator.cpp \
    parameters.cpp \
    paramsdialog.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    uniformintgenerator.h \
    chromosomepopulation.h \
    gasimulator.h \
    enumtypes.h \
    parameters.h \
    enumparser.h \
    paramsdialog.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    paramsdialog.ui

QMAKE_CXXFLAGS += -std=c++0x
