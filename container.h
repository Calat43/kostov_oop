#pragma once

#include <assert.h>

template <typename T> class Node
{
public:
    Node(T value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    T value;
    Node<T> * next;
    Node<T> * prev;
};

class EmptyContainerException : public std::logic_error
{
public:
    EmptyContainerException()
    : std::logic_error("Empty Container Error")
    {}
};

template <typename T> class Container
{
public:
    Container()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    ~Container()
    {
        clean();
        // TODO?
    }

    void addFirst(T const & value)
    {
        Node<T> * newNode = new Node<T>(value);
        if(isEmpty())
        {
            assert(last == nullptr);
            last = newNode;
        }
        else
        {
            first->prev = newNode;
        }
        newNode->next = first;
        first = newNode;

        ++size;
    }

    void addLast(T const & value)
    {
        Node<T> * newNode = new Node<T>(value);

        if(isEmpty())
        {
            assert(first == nullptr);
            first = newNode;
        }
        else
        {
            last->next = newNode;
        }
        newNode->prev = last;
        last = newNode;

        ++size;
    }

    void removeFirst() throw(EmptyContainerException)
    {
        if(isEmpty())
        {
            throw EmptyContainerException();
        }

        Node<T> * toRemove;
        toRemove = first;
        first = toRemove->next;
        if(first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            last = nullptr;
        }
        delete toRemove;

        --size;
    }

    void removeLast() throw(EmptyContainerException)
    {
        if(isEmpty())
        {
            throw EmptyContainerException();
        }

        Node<T> * toRemove;
        toRemove = last;
        last = toRemove->prev;
        if(last != nullptr)
        {
            last->next = nullptr;
        }
        else
        {
            first = nullptr;
        }
        delete toRemove;

        --size;
    }

    T getFirst() throw(EmptyContainerException)
    {
        if(isEmpty())
        {
            throw EmptyContainerException();
        }
        return first->value;
    }

    T getLast() throw(EmptyContainerException)
    {
        if(isEmpty())
        {
            throw EmptyContainerException();
        }
        return last->value;
    }

    unsigned int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (this->getSize() == 0);
    }

    void clean()
    {
        while(size != 0)
        {
            removeFirst();
        }
    }

private:
    unsigned int size;
    Node<T> * first;
    Node<T> * last;
};