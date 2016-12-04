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
//        (rand() & 1) ?
//                    list.append(Circle(Point(rand(), rand()), rand())) :
//                    list.append(Rect(rand(), rand(), rand(), rand()));
        (rand() & 1) ?
                    list.append(Circle(Point(1, 2), 3)) :
                    list.append(Rect(1, 2, 3, 5));
    }

    {
        Circle circle({1, 2}, 5);
        list.append(circle);
    }

    list.prepend(Rect(1, 2, 3, 4));

    Circle* pc = new Circle{{4, 5}, 8};
    list.prepend(*pc);
    delete pc;

    std::cout << list.removeFirst(Circle({1, 2}, 5)) << '\n';
    list.sortBySquare();
    list.sortByDistanceFromCenterToNull();
    std::cout << list;

    List copiedList = list;
    std::cout << list << copiedList;

    return 0;
}

