#-------------------------------------------------
#
# Project created by QtCreator 2015-11-20T20:31:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneticAlgorithmSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chromosome.cpp \
    uniformintgenerator.cpp \
    chromosomepopulation.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    uniformintgenerator.h \
    chromosomepopulation.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
