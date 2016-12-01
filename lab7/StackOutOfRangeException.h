#pragma once

#include <exception>
#include <string>

class StackOutOfRangeException: public std::exception
{
public:
    StackOutOfRangeException(const std::string &message);

    virtual const char *what() const noexcept override;

private:
    std::string message_;
};
