TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Counter.cpp \
    MyString.cpp

HEADERS += \
    VectorUtils.h \
    Counter.h \
    MyString.h
