#ifndef ALR3_STACK_H
#define ALR3_STACK_H

#include "LinkedList.h"

template<typename T>
class Stack
{
public:
    Stack(); // constructor

    // Function prototypes:
    void push(T value);
    T pop();
    int size() const;
    T top() const;

private:   //чтобы пользователь не видел работу листа
    LinkedList<T> list;
};

template<typename T>
Stack<T>::Stack() = default;  //выделяем память под объект класса

template<typename T>
void Stack<T>::push(T value) {
    list.pushFront(value);
}

template<typename T>
int Stack<T>::size() const {
    return list.getSize();
}

template<typename T>
T Stack<T>::pop() {
    T data = list[0]; //нашли по индексу и вытаскиваем верхний элемент (последний сверху)
    list.removeAt(0); //удаляем из стека выбранный элемент
    return data;
}

template<typename T>
T Stack<T>::top() const { //const - не изменяет лист, top- показывает чему равен самый верхний элемент
    return list[0];
}

#endif //ALR3_STACK_H
