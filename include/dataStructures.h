#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <vector>
#include <algorithm>

// MinHeap Class
template <typename T>
class MinHeap {
private:
    int length;
    std::vector<T> data;

public:
    MinHeap() : length(0), data() {}
    ~MinHeap();

    void insert(T n);
    T deleteMin();

private:
    int parent(int idx) const;
    int leftChild(int idx) const;
    int rightChild(int idx) const;
    void heapifyUp(int idx);
    void heapifyDown(int idx);
};

// Node for Single Linked List
template <typename T>
struct Node {
    T m_val;
    Node<T>* m_next;

    Node(T val) : m_val(val), m_next(nullptr) {}
};

// LinkedList Class
template <typename T>
class LinkedList {
private:
    Node<T>* m_head;

public:
    LinkedList() : m_head(nullptr) {}
    ~LinkedList();

    void add(T val);
    void pop();
};

// Node for Double Linked List
template <typename T>
struct DNode {
    T val;
    DNode<T>* next;
    DNode<T>* prev;

    DNode(T v, DNode<T>* next = nullptr, DNode<T>* prev = nullptr)
        : val(v), next(next), prev(prev) {}
};

// DoubleLinkedList Class
template <typename T>
class DoubleLinkedList {
private:
    DNode<T>* m_head;
    DNode<T>* m_tail;

public:
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) {}
    ~DoubleLinkedList();

    void push(T val);
    void pop();
};

#endif // DATA_STRUCTURES_H
