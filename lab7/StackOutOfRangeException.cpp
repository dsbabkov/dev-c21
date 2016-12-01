#include "StackOutOfRangeException.h"

StackOutOfRangeException::StackOutOfRangeException(const std::string &message)
    : message_{message}
{
}

const char *StackOutOfRangeException::what() const noexcept
{
    return message_.c_str();
}
