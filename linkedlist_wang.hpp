#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *previous;

public:
    Node() {}
    Node(T data) : data(data), next(nullptr), previous(nullptr) {}
    Node(T data, Node<T> *next) : data(data), next(next), previous(nullptr) {}
    T getData() const { return data; }
    void setData(T data) { this->data = data; }
    Node<T> *getNext() const { return next; }
    void setNext(Node<T> *next) { this->next = next; }
    Node<T> *getPrevious() const { return previous; }
    void setPrevious(Node<T> *previous) { this->previous = previous; }
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    // Default constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    DoublyLinkedList(T data) : head(nullptr), tail(nullptr), size(0) {}
    // Destructor
    ~DoublyLinkedList();

    void AddToFront(T data);
    void AddToEnd(T data);
    void AddAtIndex(T data, int index);
    void AddBefore(Node<T> *node, T data);
    void AddAfter(Node<T> *node, T data);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);
    T RemoveBefore(Node<T> *node);
    T RemoveAfter(Node<T> *node);
    bool ElementExists(T data);
    Node<T> *Find(T data);
    int IndexOf(T data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void PrintList();
    void Empty();
    int Length();
};
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Empty();
}
template <typename T>
void DoublyLinkedList<T>::AddToFront(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr)
    {
        tail = newNode;
    }
    else
    {
        head->setPrevious(newNode);
        newNode->setNext(head);
    }
    head = newNode;
    size++;
}
template <typename T>
void DoublyLinkedList<T>::AddToEnd(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (tail == nullptr)
    {
        head = newNode;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrevious(tail);
    }
    tail = newNode;
    size++;
}
template <typename T>
void DoublyLinkedList<T>::AddAtIndex(T data, int index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        AddToFront(data);
    }
    else if (index == size)
    {
        AddToEnd(data);
    }
    else
    {
        Node<T> *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->getNext();
        }
        Node<T> *newNode = new Node<T>(data, current);
        newNode->setPrevious(current->getPrevious());
        current->getPrevious()->setNext(newNode);
        current->setPrevious(newNode);
        size++;
    }
}
template <typename T>
void DoublyLinkedList<T>::AddBefore(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("Node cannot be null");
    }
    if (node == head)
    {
        AddToFront(data);
    }
    else
    {
        Node<T> *newNode = new Node<T>(data, node);
        newNode->setPrevious(node->getPrevious());
        node->getPrevious()->setNext(newNode);
        node->setPrevious(newNode);
        size++;
    }
}
template <typename T>
void DoublyLinkedList<T>::AddAfter(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("Node cannot be null");
    }
    if (node == tail)
    {
        AddToEnd(data);
    }
    else
    {
        Node<T> *newNode = new Node<T>(data, node->getNext());
        node->getNext()->setPrevious(newNode);
        node->setNext(newNode);
        newNode->setPrevious(node);
        size++;
    }
}
template <typename T>
T DoublyLinkedList<T>::RemoveFromFront()
{
    if (head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    Node<T> *temp = head;
    T data = temp->getData();
    head = temp->getNext();
    if (head != nullptr)
    {
        head->setPrevious(nullptr);
    }
    else
    {
        tail = nullptr;
    }
    delete temp;
    size--;
    return data;
}
template <typename T>
T DoublyLinkedList<T>::RemoveFromEnd()
{
    if (tail == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    T data;
    if (tail == head)
    {
        data = tail->getData();
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node<T> *temp = tail;
        tail = tail->getPrevious();
        data = temp->getData();
        tail->setNext(nullptr);
        delete temp;
    }
    size--;
    return data;
}
template <typename T>
void DoublyLinkedList<T>::RemoveTheFirst(T data)
{
    Node<T> *temp = head;
    while (temp != nullptr && temp->getData() != data)
    {
        temp = temp->getNext();
    }
    if (temp == nullptr)
    {
        return;
    }
    if (temp == head)
    {
        RemoveFromFront();
    }
    else if (temp == tail)
    {
        RemoveFromEnd();
    }
    else
    {
        temp->getPrevious()->setNext(temp->getNext());
        temp->getNext()->setPrevious(temp->getPrevious());
        delete temp;
        size--;
    }
}
template <typename T>
void DoublyLinkedList<T>::RemoveAllOf(T data)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp->getData() == data)
        {
            if (temp == head)
            {
                RemoveFromFront();
                temp = head;
            }
            else if (temp == tail)
            {
                RemoveFromEnd();
                temp = nullptr;
            }
            else
            {
                temp->getPrevious()->setNext(temp->getNext());
                temp->getNext()->setPrevious(temp->getPrevious());
                Node<T> *deleteNode = temp;
                temp = temp->getNext();
                delete deleteNode;
                size--;
            }
        }
        else
        {
            temp = temp->getNext();
        }
    }
}
template <typename T>
T DoublyLinkedList<T>::RemoveBefore(Node<T> *node)
{
    if (node == nullptr || node == head)
    {
        throw std::invalid_argument("Invalid node provided");
    }
    if (node == tail)
    {
        return RemoveFromEnd();
    }
    T data;
    Node<T> *temp = node->getPrevious();
    if (temp == head)
    {
        data = RemoveFromFront();
    }
    else
    {
        temp->getPrevious()->setNext(node);
        node->setPrevious(temp->getPrevious());
        data = temp->getData();
        delete temp;
        size--;
    }
    return data;
}
template <typename T>
T DoublyLinkedList<T>::RemoveAfter(Node<T> *node)
{
    if (node == nullptr || node->getNext() == nullptr)
    {
        throw std::invalid_argument("Invalid node or node has no next element");
    }
    Node<T> *del = node->getNext();
    T data = del->getData();
    node->setNext(del->getNext());
    if (del->getNext() != nullptr)
    {
        del->getNext()->setPrevious(node);
    }
    else
    {
        tail = node;
    }
    delete del;
    size--;
    return data;
}
template <typename T>
bool DoublyLinkedList<T>::ElementExists(T data)
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->getData() == data)
        {
            return true;
        }
        current = current->getNext();
    }
    return false;
}
template <typename T>
Node<T> *DoublyLinkedList<T>::Find(T data)
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->getData() == data)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}
template <typename T>
int DoublyLinkedList<T>::IndexOf(T data)
{
    Node<T> *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->getData() == data)
        {
            return index;
        }
        current = current->getNext();
        index++;
    }
    return -1;
}
template <typename T>
T DoublyLinkedList<T>::RetrieveFront()
{
    if (head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    return head->getData();
}
template <typename T>
T DoublyLinkedList<T>::RetrieveEnd()
{
    if (tail == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    return tail->getData();
}
template <typename T>
T DoublyLinkedList<T>::Retrieve(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node<T> *current = head;
    int i = 0;
    while (i < index)
    {
        current = current->getNext();
        i++;
    }
    return current->getData();
}
template <typename T>
void DoublyLinkedList<T>::PrintList()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}
template <typename T>
void DoublyLinkedList<T>::Empty()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *temp = current->getNext();
        delete current;
        current = temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename T>
int DoublyLinkedList<T>::Length()
{
    return size;
}
#endif
