#pragma once

#include <exception>
#include <string>

class MyException: public std::exception
{
public:
    MyException(const std::string &message);

    virtual const char *what() const noexcept override;

private:
    std::string message_;
};
