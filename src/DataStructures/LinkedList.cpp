#include "../../include/DataStructures/LinkedList.h"

template<typename T>
node<T>::node(T val) : m_val(val), m_next(nullptr) {}

template<typename T>
LinkedList<T>::LinkedList() : m_head(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (m_head) {
        pop();
    }
}

template<typename T>
void LinkedList<T>::add(T val) {
    node<T> *newNode = new node<T>(val);
    if (m_head == nullptr) {
        m_head = newNode;
    } else {
        node<T> *tmp = m_head;
        while (tmp->m_next) {
            tmp = tmp->m_next;
        }
        tmp->m_next = newNode;
    }
}

template<typename T>
void LinkedList<T>::pop() {
    if (m_head == nullptr) {
        return;
    } else if (m_head->m_next == nullptr) {
        delete m_head;
        m_head = nullptr;
    } else {
        node<T> *tmp = m_head;
        while (tmp->m_next->m_next) {
            tmp = tmp->m_next;
        }
        delete tmp->m_next;
        tmp->m_next = nullptr;
    }
}

