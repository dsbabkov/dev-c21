QT += core
QT -= gui

TARGET = lab6
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Shape.cpp \
    Point.cpp \
    Rect.cpp \
    Circle.cpp \
    Node.cpp \
    List.cpp

HEADERS += \
    Shape.h \
    Point.h \
    Rect.h \
    Circle.h \
    Node.h \
    List.h

