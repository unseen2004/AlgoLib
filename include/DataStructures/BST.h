#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class BST {
private:
    struct Node {
        T m_data;
        Node* m_left;
        Node* m_right;

        Node(T data);
    };

    Node* m_root;

public:
    BST();
    ~BST();

    void insert(T value);
    bool remove(T value);
    bool contains(T value) const;
    T getMin() const;
    T getMax() const;
    int getHeight() const;
    void printInOrder() const;

private:
    Node* insert(Node* node, T value);
    Node* remove(Node* node, T value);
    bool contains(Node* node, T value) const;
    Node* getMinNode(Node* node) const;
    Node* getMaxNode(Node* node) const;
    int getHeight(Node* node) const;
    void printInOrder(Node* node) const;
    void clear(Node* node);
};


#endif // BST_H
