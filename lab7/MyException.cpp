#include "MyException.h"

MyException::MyException(const std::string &message)
    : message_{message}
{
}

const char *MyException::what() const noexcept
{
    return message_.c_str();
}
