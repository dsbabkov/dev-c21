#include "QueueUnderflowException.h"

QueueUnderflowException::QueueUnderflowException(const std::string &message)
    : MyException{message}
{
}
