#pragma once

#include "MyException.h"

class StackOutOfRangeException: public MyException
{
public:
    StackOutOfRangeException(const std::string &message);
};
