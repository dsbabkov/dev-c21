#pragma once

template<class T>
class MyStack2;

template <class T>
class Node{
    friend class MyStack2<T>;
public:
    Node(Node *after, const T &value)
        : prev_{after}
        , value_{value}
    {}

private:
    Node *prev_;
    T value_;
};
