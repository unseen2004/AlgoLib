#include "../../include/DataStructures/DoubleLinkedList.h"

template<typename T>
Node<T>::Node(T v, Node<T> *next, Node<T> *prev) : val(v), next(next), prev(prev) {}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) {}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (m_tail) {
        pop();
    }
}

template<typename T>
void DoubleLinkedList<T>::push(T val) {
    Node<T> *newNode = new Node<T>(val, nullptr, nullptr);
    if (m_tail == nullptr) {
        m_head = m_tail = newNode;
    } else {
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

template<typename T>
void DoubleLinkedList<T>::pop() {
    if (m_tail == nullptr) {
        return;
    } else if (m_tail == m_head) {
        delete m_tail;
        m_tail = m_head = nullptr;
    } else {
        Node<T> *toDel = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        delete toDel;
    }
}
