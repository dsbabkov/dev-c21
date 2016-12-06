#include "MyQueue.h"
#include "MyStack.h"
#include "MyStack2.h"
#include "MyString.h"
#include "Swap.h"
#include <stdexcept>

#define stop {bool tmp{}; tmp = tmp};

int main()
{
	

////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);


	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
    MyString str1("One"), str2("Two");
    Swap(str1, str2);

/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]

    MyStack<int, 5> iStack;
    try {
        for (int i = 0; ; ++i){
            iStack.push(i);
        }
    } catch (const StackOverflowException &exception){
        std::cout << exception.what() << "\n";
    }

    try{
        while (true){
            std::cout << iStack.pop() << '\n';
        }
    } catch (const StackUnderflowException &exception){
        std::cout << exception.what() << '\n';
    }

    MyStack<MyString> strStack;
    try {
        while(true){
            strStack.push("strStackElement");
        }
    } catch (const StackOverflowException &exception){
        std::cout << exception.what() << "\n";
    }

    try{
        while (true){
            std::cout << strStack.pop() << '\n';
        }
    } catch (const StackUnderflowException &exception){
        std::cout << exception.what() << '\n';
    }


	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь


    {
        MyStack2<int> stack;
        for (int i = 0; i < 5; ++i){
            stack.push(i);
        }
        MyStack2<int> copy = stack;
        copy.reverse();
        std::cout <<"Copy\n";
        copy.printElements();
        MyStack2<int> move;
        move = std::move(stack);
        std::cout <<"Move\n";
        move.printElements();
        std::cout <<"Original\n";
        stack.printElements();

    }




	//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
	//для хранения элементов использовался динамический массив.
	//При использовании массива следует учесть специфику очереди, то есть
	//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
	//=> должен быть организован кольцевой буфер

    {
        MyQueue<int> q;
        for (int i = 1; i < 6; ++i){
            q.push(i);
        }

        std::cout << q.pop() << '\n';
        q.push(6);
        q.push(7);

        MyQueue<int> qMove = std::move(q);
        q = std::move(qMove);
        std::cout << "Original\n";
        try{
            while(true){
                std::cout << q.pop() << '\n';
            }
        } catch(const QueueUnderflowException &exception) {
            std::cout << exception.what() << '\n';
        }

        std::cout << "Move\n";
        try{
            while(true){
                std::cout << qMove.pop() << '\n';
            }
        } catch(const QueueUnderflowException &exception) {
            std::cout << exception.what() << '\n';
        }
    }


	return 0;
}

