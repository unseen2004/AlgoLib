#ifndef NODE_H
#define NODE_H

template<typename T>
struct node {
    T m_val;
    node<T> *m_next;

    node(T val) : m_val(val), m_next(nullptr) {}
};

template<typename T>
struct Node {
    T val;
    Node<T> *next;
    Node<T> *prev;

    Node(T v, Node<T> *next = nullptr, Node<T> *prev = nullptr)
            : val(v), next(next), prev(prev) {}
};

#endif // NODE_H
