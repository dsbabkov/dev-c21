// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include "ContainerUtils.h"

#include "Point.h"

using namespace std;	
#define	  stop {bool tmp{}; tmp = tmp;}


int main()
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию
    set<Point> pointSet{
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    vector<Point> pointVec(pointSet.crbegin(), pointSet.crend());

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

    ostream_iterator<Point> outIt(cout, ", ");
    std::copy(pointSet.cbegin(), pointSet.cend(), outIt);
    std::cout << "\n";
    std::copy(pointVec.cbegin(), pointVec.cend(), outIt);
    std::cout << "\n";

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
    //итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
    std::copy(pointSet.cbegin(), pointSet.cend(), back_inserter(pointVec));
    std::copy(pointVec.cbegin(), pointVec.cend(), outIt);
    std::cout << "\n";



///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
    printWithForEach(pointVec);


	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

    for_each(pointVec.begin(), pointVec.end(), [](Point &point){point.setX(point.x() + 1);});
    printWithForEach(pointVec);




	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
    Point myPoint(4, 4);
    auto it = find(pointVec.cbegin(), pointVec.cend(), myPoint);
    while (it != pointVec.cend()){
        cout << it - pointVec.cbegin() << " ";
        it = find(it + 1, pointVec.cend(), myPoint);
    }
    cout << '\n';


	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
    sort(pointVec.begin(), pointVec.end());
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	



	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

    const double n = 4;
    const double m = 5;
    find_if(pointVec.cbegin(), pointVec.cend(), [=](const Point &point){return point.x() < n && point.y() > m;});


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
    sort(pointVec.begin(), pointVec.end(), [](const Point &left, const Point &right){return left.vectorLength() < right.vectorLength();});


	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
        string str = "AAAAAbbBbAAAa";
        transform(str.cbegin(), str.cend(), str.begin(), [](char c){return c | 0x20;});
//        for_each(str.begin(), str.end(), [](char &c){c |= 0x20;});
        cout << str << '\n';


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
        list<string> strList = {
            "MY",
            "BIG",
            "BIG",
            "BIG",
            "BIG",
            "STRINGS"
        };
	
        set<string> strSet;
        transform(strList.cbegin(), strList.cend(), inserter(strSet, strSet.begin()), [](const string &str){
            string result(str);
            for_each(result.begin(), result.end(), [](char &c){c |= 0x20;});
            return result;
        });



		stop

    // map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	
    map<string, int> strMap;
    for (const string &str: strList){
        ++strMap[str];
    };


    for (const auto &pair: strMap){
        cout << pair.first << ": " << pair.second << "\n";
    }

	}


	return 0;
}

