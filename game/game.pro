#-------------------------------------------------
#
# Project created by QtCreator 2015-06-17T00:29:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES +=main.cpp\
        game.cpp \
    squaremap.cpp \
    destroy.cpp \
    star.cpp \
    vertical.cpp \
    horizontal.cpp \
    nineblock.cpp \
    vertical3.cpp \
    horizontal3.cpp \

HEADERS  += game.h \
    squaremap.h \
    destroy.h \
    star.h \
    vertical.h \
    horizontal.h \
    nineblock.h \
    vertical3.h \
    horizontal3.h

FORMS    += game.ui \


RESOURCES += \
    pic.qrc
