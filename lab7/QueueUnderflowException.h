#pragma once

#include "MyException.h"

class QueueUnderflowException: public MyException
{
public:
    QueueUnderflowException(const std::string &message);
};
