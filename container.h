#pragma once

template <typename T> class Container
{
public:
    Container()
    {

    }

    ~Container()
    {
        clean();
        // TODO
    }

    void addFirst(T const & value)
    {

    }

    void addLast(T const & value)
    {

    }

    void removeFirst()
    {

    }

    void removeLast()
    {

    }

    T getFirst()
    {

    }

    T getLast()
    {

    }

    unsigned int getSize()
    {

    }

    bool isEmpty()
    {
        return (this->getSize() == 0);
    }

    void clean()
    {

    }

private:


};


template <typename T> class Node
{
public:
    Node(T value)
    {

    }

    T value;
    Node * next;
};