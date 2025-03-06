#include "Queue.h"

template <typename T>
Queue<T>::Queue() : m_front{nullptr}, m_tail{nullptr}, m_size{0} {}

template <typename T>
Queue<T>::~Queue() {
    while (!is_empty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T data) {
    Node<T>* new_node = new Node<T>{data};
    if (m_tail) {
        m_tail->next = new_node;
    } else {
        m_front = new_node;
    }
    m_tail = new_node;
    m_size++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (is_empty()) {
        throw std::underflow_error{"Queue is empty. Cannot dequeue."};
    }

    Node<T>* tmp = m_front;
    m_front = m_front->next;
    delete tmp;
    m_size--;

    if (!m_front) {
        m_tail = nullptr;
    }
}

template <typename T>
T Queue<T>::peek() const {
    if (is_empty()) {
        throw std::underflow_error{"Queue is empty. Cannot peek."};
    }
    return m_front->data;
}

template <typename T>
int Queue<T>::size() const {
    return m_size;
}

template <typename T>
bool Queue<T>::is_empty() const {
    return m_size == 0;
}
