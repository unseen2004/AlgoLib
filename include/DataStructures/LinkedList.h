#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
    node<T> *m_head;

public:
    LinkedList();
    ~LinkedList();
    void add(T val);
    void pop();
};

#endif // LINKEDLIST_H

