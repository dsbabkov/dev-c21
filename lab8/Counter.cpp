#include "Counter.h"
#include <cstring>

Counter::Counter(const char * str, Counter *before)
    : next_{}
    , str_{new char[strlen(str) + 1]}
    , owners_{}
{
    if (before){
        next_ = before->next_;
        before->next_ = this;
    }

    strcpy(str_, str);
}

Counter::~Counter()
{
    delete[] str_;
}

void Counter::addOwner()
{
    ++owners_;
}

void Counter::removeOwner()
{
    --owners_;
}

bool Counter::hasOwners() const
{
    return owners_;
}

unsigned Counter::owners() const
{
    return owners_;
}

const char *Counter::str() const
{
    return str_;
}

Counter *Counter::next() const
{
    return next_;
}

void Counter::setNext(Counter *next)
{
    next_ = next;
}

void Counter::toggleStringCase()
{
    for (char *p = str_; *p != '\0'; ++p){
        *p ^= 0x20;
    }
}

bool operator ==(const Counter &counter, const char *str)
{
    return !strcmp(counter.str(), str);
}

bool operator <(const Counter &left, const Counter &right)
{
    return strcmp(left.str(), right.str()) < 0;
}
