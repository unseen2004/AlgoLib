#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template<typename T>
class DoubleLinkedList {
    Node<T> *m_head;
    Node<T> *m_tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void push(T val);
    void pop();
};

#endif // DOUBLELINKEDLIST_H
