#pragma once

#include <iostream>

class Counter;

class MyString
{
public:
    MyString(const char *str = "");
    MyString(const MyString &other);
    MyString(MyString &&other);
    ~MyString();

    MyString &operator = (const MyString &other);
    MyString &operator = (MyString &&other);
    MyString &operator = (const char *str);

    const char *cStr() const;

    static void printAllStrings();
    static void printOrderedStrings();
    static unsigned counterCount();
    static void debugPrintCountersCount();
    static void toggleStringsCase();

private:
    void decrementCounter();
    static Counter *counterForString(const char *str);
    static void deleteCounter(Counter *counter_);
    static void excludeCounterFromList(Counter *counter_);


private:
    static Counter *counters_;
    Counter *counter_;
};

std::ostream & operator << (std::ostream &os, const MyString &str);
