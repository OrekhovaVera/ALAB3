#ifndef ALR3_QUEUE_H
#define ALR3_QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue
{
public:
    Queue();
    void push(T data);
    T pop();
    T front() const;
    bool isEmpty() const;
    int size() const;

private:
    LinkedList<T> list;
};

template<typename T> //дефолтный конструктор для класса
Queue<T>::Queue()
= default;

template<typename T>
void Queue<T>::push(T data) //добавляем элемент в очередь
{
    list.pushBack(data);
}

template<typename T>
T Queue<T>::pop()  //получаем первый (передний) элемент очереди
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    T data = list[0];
    list.popFront();
    return data;
}

template<typename T>
T Queue<T>::front() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    return list[0];
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return list.getSize() == 0;
}

template<typename T>
int Queue<T>::size() const  //получаем размер очереди
{
    return list.getSize();
}


#endif //ALR3_QUEUE_H
