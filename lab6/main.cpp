#include "Circle.h"
#include "List.h"
#include "Rect.h"
#include <ctime>
#include <iostream>
#include <random>

int main()
{
    srand(time(nullptr));
    List list;

    for (int i = 0; i < 5; ++i){
        (rand() & 1) ?
                    list.append(Circle(Point(rand(), rand()), rand())) :
                    list.append(Rect(rand(), rand(), rand(), rand()));
    }

    {
        Circle circle({1, 2}, 5);
        list.append(circle);
    }

    list.prepend(Rect(1, 2, 3, 4));

    Circle circle({1, 2}, 5);
    Shape *s1 = circle.clone();
    Shape *s2 = circle.clone();

    std::cout << (*s1 == *s2) << '\n';

    Circle* pc = new Circle;
    list.prepend(*pc);
    delete pc;

//    std::cout << list.removeFirst(Circle({1, 2}, 5)) << '\n';
    std::cout << list;

    return 0;
}

