TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    MyString.cpp \
    Counter.cpp \
    StackOverflowException.cpp \
    StackUnderflowException.cpp \
    StackOutOfRangeException.cpp

HEADERS += \
    MyString.h \
    Counter.h \
    Swap.h \
    MyStack.h \
    StackOverflowException.h \
    StackUnderflowException.h \
    StackOutOfRangeException.h \
    MyStack2.h
