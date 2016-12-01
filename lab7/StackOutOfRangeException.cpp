#include "StackOutOfRangeException.h"

StackOutOfRangeException::StackOutOfRangeException(const std::string &message)
    : MyException{message}
{
}
