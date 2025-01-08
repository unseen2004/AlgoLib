#ifndef TREE_ALGORITHMS_H
#define TREE_ALGORITHMS_H

#include "Node.h"
#include <queue>
#include <vector>

template<typename T>
bool compareTrees(Node<T> *a, Node<T> *b);

template<typename T>
bool breadthFirstSearch(Node<T> *head, T target);

template<typename T>
bool depthFirstSearch(Node<T> *head, T target);

template<typename T>
std::vector<T> preOrderTraversal(Node<T> *head);

#endif // TREE_ALGORITHMS_H
