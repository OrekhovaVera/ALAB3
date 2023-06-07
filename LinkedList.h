#ifndef ALR3_LINKEDLIST_H
#define ALR3_LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList
{
public:
    LinkedList();
    void insertAt(T data, int index);
    void removeAt(int index);
    void removeValue(T data);
    void popBack();
    void print() const;
    void pushFront(T data);
    void pushBack(T data);
    void popFront();
    void clear();
    int search(T data) const;
    int getSize() const { return size; }
    T& operator[](int index) const;

private:
    template<typename U>
    class Node
    {
    public:
        Node* next;
        U data;

        Node(U value = U(), Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node<T>* head;
    int size;
};

template<typename T>
LinkedList<T>::LinkedList()  // создаем конструктор
{
    size = 0;
    head = nullptr;
}

template<typename T>
void LinkedList<T>::pushBack(T data) // добавляем элемент в конец листа
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* currNode = head;
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = new Node<T>(data);
    }
    size++; // увеличиваем переменную size на 1, так как в список добавляется новый элемент
}

template<typename T>
T& LinkedList<T>::operator[](const int index) const // перегруженный оператор возвращает ссылку на значение элемента по указанному индексу
{
    int counter = 0;
    Node<T>* currNode = head;
    while (currNode != nullptr)
    {
        if (counter == index)
            return currNode->data;
        currNode = currNode->next;
        counter++;
    }
    throw std::out_of_range("Index out of range"); // выбрасываем исключение, если не существует элемента с указанным индексом
}

template<typename T>
void LinkedList<T>::popFront() // удаляем первый элемент из листа
{
    if (head == nullptr)
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<typename T>
void LinkedList<T>::pushFront(T data) // добавляем элемент в начало списка
{
    head = new Node<T>(data, head);
    size++;
}

template<typename T>
void LinkedList<T>::insertAt(T data, int index) // добавляем элемент по указанному индексу
{
    try
    {
        if (index == 0)
        {
            pushFront(data);
        }
        else
        {
            Node<T>* previousNode = head;
            for (int i = 0; i < index - 1; ++i)
            {
                if (previousNode == nullptr)
                    throw std::out_of_range("Index out of range");
                previousNode = previousNode->next;
            }
            if (previousNode == nullptr)
                throw std::out_of_range("Index out of range");
            Node<T>* newNode = new Node<T>(data, previousNode->next);
            previousNode->next = newNode;
            size++;
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << "Error occurred while inserting an element: " << e.what() << std::endl;
    }
}

template<typename T>
void LinkedList<T>::print() const // выводим все элементы связанного списка
{
    Node<T>* currNode = head;
    std::cout << "List: ";
    while (currNode != nullptr)
    {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::removeAt(int index) // удаляем элемент по указанному индексу
{
    try
    {
        if (index == 0)
        {
            popFront();
        }
        else
        {
            Node<T>* previousNode = head;
            for (int i = 0; i < index - 1; ++i)
            {
                previousNode = previousNode->next;
            }
            Node<T>* toDelete = previousNode->next;
            previousNode->next = toDelete->next;
            delete toDelete;
            size--;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error occurred while removing an element at the index. Index is out of range." << e.what() << std::endl;
    }
}

template<typename T>
void LinkedList<T>::popBack() // возвращаем и удаляем последний элемент из списка
{
    if (head == nullptr)
    {
        return;
    }
    removeAt(size - 1);
}

template<typename T>
void LinkedList<T>::removeValue(T data) // удаляем элемент по значению (учитывая его первое вхождение)
{
    Node<T>* currNode = head;
    Node<T>* previousNode = nullptr;
    while (currNode != nullptr)
    {
        if (currNode->data == data)
        {
            if (previousNode == nullptr)
            {
                popFront();
            }
            else
            {
                previousNode->next = currNode->next;
                delete currNode;
                size--;
            }
            return;
        }
        previousNode = currNode;
        currNode = currNode->next;
    }
}

template<typename T>
int LinkedList<T>::search(T data) const // поиск элемента по его первому вхождению
{
    Node<T>* currNode = head;
    int index = 0;
    while (currNode != nullptr)
    {
        if (currNode->data == data)
        {
            return index;
        }
        currNode = currNode->next;
        index++;
    }
    return -1;
}


#endif //ALR3_LINKEDLIST_H
