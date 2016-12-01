#pragma once

#include "StackOutOfRangeException.h"

class StackUnderflowException: public StackOutOfRangeException
{
public:
    explicit StackUnderflowException(const std::string &message);
};
