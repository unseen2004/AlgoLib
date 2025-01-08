#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
using namespace std;

enum Color { RED, BLACK };

template <typename T>
class RedBlackTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        Color color;

        Node(T data);
    };

    Node* root;

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(T data);
    bool remove(T data);
    bool contains(T data) const;
    void printInOrder() const;

private:
    Node* bstInsert(Node* root, Node* newNode);
    void rotateLeft(Node*& root, Node*& pt);
    void rotateRight(Node*& root, Node*& pt);
    void fixInsert(Node*& pt);
    void deleteNode(Node* node);
    void fixDelete(Node* x, Node* x_parent);
    Node* search(Node* root, T data) const;
    Node* getMinNode(Node* node) const;
    void transplant(Node* u, Node* v);
    void printInOrder(Node* root) const;
    void clear(Node* node);
    Node* getSibling(Node* node);
};


#endif // REDBLACKTREE_H
