#pragma once

class Counter
{
    Counter(const Counter &other) = delete;
    Counter &operator = (const Counter &ohter) = delete;

public:
    Counter(const char * str = "", Counter *before = nullptr);
    ~Counter();

    void addOwner();
    void removeOwner();
    bool hasOwners() const;
    unsigned owners() const;

    const char *str() const;

    Counter *next() const;
    void setNext(Counter *next);

    void toggleStringCase();

private:
    Counter *next_;
    char *str_;
    unsigned owners_;
};

bool operator == (const Counter &counter, const char *str);
bool operator < (const Counter &left, const Counter &right);
