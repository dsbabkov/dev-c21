#include "StackUnderflowException.h"

StackUnderflowException::StackUnderflowException(const std::string &message)
    : StackOutOfRangeException{message}
{
}
