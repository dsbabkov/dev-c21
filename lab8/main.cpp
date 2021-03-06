//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include "ContainerUtils.h"
#include "VectorUtils.h"
#include "MyString.h"
#include "Point.h"
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>


using namespace std;	

#define	  stop {bool tmp{}; tmp = tmp;}


int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
    {
        vector<int> vInt;
        std::cout << "vInt size: " << vInt.size() << '\n';
	
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

        vInt.reserve(1);
        vInt.front()=1;

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
        for (int i = 0; i < 10; ++i){
            vInt << i;
            std::cout << vInt << "\n\n";
        }



	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
            vector<double> vDouble1(5);
            std::cout << vDouble1 << "\n\n";


	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
        vector<MyString> vStr(5, "A");

        vStr.at(1) = "B";
        vStr[2] = "C";
        try{
            vStr.at(5) = "E";
        }
        catch(const out_of_range &){
//            vStr.reserve(6);
//            vStr[5] = "E";
        }





	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
        vector<double> dMas = {0, 1, 2, 3, 4, 5, 6, 7};
        std::cout << dMas << "\n\n";
        vector<double> vDouble3(dMas.cbegin(), dMas.cbegin() + 5);
        std::cout << vDouble3 << "\n\n";

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
        vector<double> vDouble4(vDouble3.cbegin() + 2, vDouble3.cend());
        std::cout << vDouble4 << "\n\n";




	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
        vector<Point> vPoint1(3); // default constructor
        vector<Point> vPoint2(5, {1,1});
        std::cout << vPoint1 << "\n\n" << vPoint2 << "\n\n";


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
        vector<Point *> vpPoint = {
            new Point{1, 2},
            new Point{3, 4}
        };
        printContainer (vpPoint);
        {

        //Подсказка: для вывода на печать значений скорее всего Вам понадобится
            //а) специализация Вашей шаблонной функции
            //б) или перегрузка operator<< для Point*

        }//Какие дополнительные действия нужно предпринять для такого вектора?

    }

	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
    {
        const size_t n = 5;
		vector<int> v(n);
		v.resize(n/2);
		if(v.capacity() == n) //true?
//            false;
        {}
    }



    {
        const int n = 5;
        const size_t m = 4;
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) //true?
        {
//            true;
//            false;
        }
    }



    {
		vector<int> v(3,5);
        v.resize(4,10); //значения? {5, 5, 5, 10}
        v.resize(5); //значения? {5, 5, 5, 10, 0}
        stop
    }

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
    {
        std::vector<int> a, b;
        a.reserve(5);
        for (int i = 0; i < 5; ++i){
            a.push_back(i);
            b.push_back(i);
        }

        std::cout << a << "\n\n" << b << "\n\n";

        //a.capasity != b.capacity()


	



	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

        b.shrink_to_fit();
        std::cout << a << "\n\n" << b << "\n\n";

        //a.capasity == b.capacity()
    }

	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
    //Распечатайте содержимое такого двухмерного вектора по строкам
    {
        int ar[] = {11,2,4,3,5};
        size_t size = sizeof(ar) / sizeof(*ar);
        vector<vector<int>> mat(size);
        for (size_t i = 0; i < size; ++i){
            vector<int> &vec = mat[i];
            vec.resize(ar[i], ar[i]);
            cout << vec << "\n";
        }
        stop
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.

    {
        vector<char> vChar2;
        for (char c: "qwerrrrty12222r3"){
            vChar2.push_back(c);
        }

        const char c = 'r';
        if (std::find(vChar2.cbegin(), vChar2.cend(), c) != vChar2.cend()){
            vChar2.insert(vChar2.begin(), c);
        }
	
	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
        for (size_t i = 0; i < vChar2.size(); i += 2){
            vChar2.insert(vChar2.begin() + i, 'W');
        }
	
        cout << vChar2;


///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"

        vector<char> vChar;
        for (char c: "qwerrrrty12222r3"){
            vChar.push_back(c);
        }

        removePeriodicity(vChar);

        cout << vChar << "\n\n";
    }

///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 
    {
        vector<int> vec = {1, 2, 3, 1, 2, 3, 1, 1, 1, 2, 2, 3, 3, 3, 4};
        removeDuplicates(vec);
        cout << vec << "\n\n";
    }


	

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке

    {
        vector<int> vec = {1, 2, 3};
        cout << reversedVector(vec) << "\n\n";
    }



///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
    {
        list<Point> ptList1;
        ptList1.push_back({1, 2});
        ptList1.push_back({2, -9});
        ptList1.push_back({4, 9});
        ptList1.push_back({5, 2});
        ptList1.push_back({15, 32});

        vector<Point> ptVector1;
        ptVector1.push_back({1, 2});
        ptVector1.push_back({2, -9});
        ptVector1.push_back({4, 9});
        ptVector1.push_back({5, 2});
        ptVector1.push_back({15, 32});

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

        printContainer(ptList1);
        std::cout << '\n';
        printContainer(ptVector1);
        std::cout << '\n';


	//Сделайте любой из списков "реверсивным" - reverse()
        reversedContainer(ptList1);
        reversedContainer(ptVector1);
        printContainer(ptList1);
        std::cout << '\n';
        printContainer(ptVector1);
        std::cout << '\n';


	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 

        list<Point> ptList2(ptVector1.crbegin(), ptVector1.crend());


	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка
        ptList1.sort();
        ptList2.sort();


	


	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

        printContainer(ptList1);
        std::cout << '\n';
        printContainer(ptList2);
        std::cout << '\n';
        ptList1.merge(ptList2);
        printContainer(ptList1);
        std::cout << '\n';

	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	
        ptList1.remove({1, 2});
        printContainer(ptList1);
        std::cout << '\n';

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 

        ptList1.remove_if([](const Point &point){return point.x() < 0 || point.y() < 0;});
        printContainer(ptList1);
        std::cout << '\n';


	//Исключение из списка подряд расположенных дублей - unique(). 
        ptList1.unique();
        printContainer(ptList1);
        std::cout << '\n';

	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
        std::deque<Point> deq;
        deq.assign(ptVector1.cbegin(), ptVector1.cend());
        printContainer(deq);
        std::cout << '\n';


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
        std::deque<MyString> strDeq;
        strDeq.push_back("Are");
        strDeq.push_back("Arre");
        strDeq.push_back("arqwere");
        strDeq.push_back("Arffde");
        strDeq.push_back("Aertvre");
        strDeq.insert(strDeq.begin() + 2, 2, "Bgg");

        printContainer(strDeq);
        std::cout << '\n';

        for (size_t end = strDeq.size(), i = end - 1; i < end; --i){
            if ((*strDeq[i].cStr() | 0x20) == 'a'){
                strDeq.erase(strDeq.begin() + i);
            }
        }

        printContainer(strDeq);
        std::cout << '\n';



    }
	return 0;
}
