#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

template<typename T>
class AVLTree {
private:
    struct Node {
        T m_data;
        Node* m_left;
        Node* m_right;
        int m_height;

        Node(T data);
    };

    Node* m_root;

public:
    AVLTree();
    ~AVLTree();

    void insert(T value);
    bool remove(T value);
    bool contains(T value) const;
    int getHeight() const;
    void printInOrder() const;

private:
    Node* insert(Node* node, T value);
    Node* remove(Node* node, T value);
    bool contains(Node* node, T value) const;
    Node* balance(Node* node);
    int getBalanceFactor(Node* node) const;
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    int getHeight(Node* node) const;
    int max(int a, int b) const;
    void printInOrder(Node* node) const;
    Node* getMinNode(Node* node) const;
    void clear(Node* node);
};

#endif // AVLTREE_H
