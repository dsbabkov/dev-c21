#pragma once

#include "StackOutOfRangeException.h"

class StackOverflowException: public StackOutOfRangeException
{
public:
    explicit StackOverflowException(const std::string &message);
};
