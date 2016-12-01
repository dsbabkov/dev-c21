#include "StackOverflowException.h"

StackOverflowException::StackOverflowException(const std::string &message)
    : StackOutOfRangeException{message}
{
}
