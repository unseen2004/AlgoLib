#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    T val;
    Node<T> *left;
    Node<T> *right;

    Node(T x) : val(x), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
