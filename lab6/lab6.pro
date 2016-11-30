QT += core
QT -= gui

TARGET = lab6
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Point.cpp \
    Rect.cpp \
    Circle.cpp \
    Node.cpp \
    List.cpp \
    IShape.cpp \
    AbstractColoredShape.cpp

HEADERS += \
    Point.h \
    Rect.h \
    Circle.h \
    Node.h \
    List.h \
    IShape.h \
    AbstractColoredShape.h

