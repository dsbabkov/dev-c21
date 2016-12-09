// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "AdapterUtils.h"
#include "AssociativeUtils.h"
#include "Point.h"
#include <cstring>

#include <iostream>

#define stop {bool tmp = {}; tmp = tmp;}

int main()
{

	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	




	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::stack<int, std::vector<int>> stack({vec.crbegin(), vec.crend()});
    const int &(std::stack<int, std::vector<int>>::*stackTopMethod)() const = &std::stack<int, std::vector<int>>::top;
    std::queue<int> queue({vec.cbegin(), vec.cend()});
    std::priority_queue<int> priority_queue({vec.cbegin(), vec.cend()});
    printAdapter(stack, stackTopMethod);
    printAdapter(queue, &std::queue<int>::front);
    printAdapter(priority_queue, &std::priority_queue<int>::top);


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
    {
        std::queue<Point *, std::deque<Point *>> pointPointersQueue{{
            new Point(), new Point(), new Point(), new Point(), new Point()
        }};

        pointPointersQueue.front()->setX(1);
        pointPointersQueue.back()->setY(1);

        while (!pointPointersQueue.empty()){
            delete pointPointersQueue.front();
            pointPointersQueue.pop();
        }
    }
	







	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
    struct CompareStr{
        bool operator () (const char *l, const char *r){
            return strcmp(l, r) < 0;
        }
    };

    {
        std::vector<const char *> ivec = {"b" , "a", "A", "v"};
        std::priority_queue<const char *, std::vector<const char *>, CompareStr> priorChar(ivec.cbegin(), ivec.cend());

        printAdapter(priorChar,
                     &std::priority_queue<const char *, std::vector<const char *>, CompareStr>::top);
    }


	




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

    std::set<Point> pointSet{{1,2}, {3, 4}, {5, 6}};
    std::set<Point> copyPointSet(pointSet);
    std::vector<Point> vecPoint(pointSet.cbegin(), pointSet.cend());
    vecPoint.push_back({1,1});
    copyPointSet.insert(vecPoint.cbegin(), vecPoint.cend());




	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

    std::map<const char *, int> salaryMap;
    salaryMap["Pupkin"] = 100;
    salaryMap.insert({"Petrischev", 200});

    printAssociative(salaryMap);
    auto mapIt = salaryMap.find("Petrischev");
    if (mapIt != salaryMap.end()){
        salaryMap.insert({"Releeva", mapIt->second});
        salaryMap.erase(mapIt);
    }
	

	
		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

    std::vector<std::string> strVec {"pen", "pineapple", "apple", "pen"};
    std::map<std::string, int> strMap;
    for (const std::string &string: strVec){
        strMap[string];
    }
    printAssociative(strMap);




		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
    const char* words[] = {"Abba", "Alfa", "Beta", "Beauty"};
    std::map<char, std::set<const char *, CompareStr> > myMap;
    for (const char *word: words){
        myMap[word[0]].insert(word);
    }
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
		

		//ж)
    struct Student{
        std::string lastName;
        int id;

        bool operator <(const Student &other) const{
            int compareResult = strcmp(lastName.c_str(), other.lastName.c_str());

            return compareResult == 0 ?
                        id < other.id :
                        compareResult < 0;
        }
    };

    struct StudentGroup{
        int id;
        std::set<Student> students;

        bool operator < (const StudentGroup &other) const{
            return id < other.id;
        }
    };
    std::set<StudentGroup> studentGroups;

		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 




	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
    std::multimap<std::string, std::string> englishRussian = {
        {"strange", {"chuzoi", "strannii"}}
    };

    for (const auto &mapPair: englishRussian){
        std::cout << mapPair.first << ": ";
        for (const auto &string: englishRussian.equal_range()){
            std::cout << string << ' ';
        }
        std::cout << '\n';
    }


   

  stop

	return 0;
}

