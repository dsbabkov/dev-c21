#include "QueueUnderflowException.h"

QueueUnderflow::QueueUnderflow(const std::string &message)
    : MyException{message}
{
}
