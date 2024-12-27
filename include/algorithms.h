#ifndef GRAPH_AND_SEARCH_ALGORITHMS_H
#define GRAPH_AND_SEARCH_ALGORITHMS_H

#include <vector>
#include <algorithm>

template<typename T>
struct Node {
    T val;
    Node<T> *next;
    Node<T> *prev;

    Node(T x) : val(x), next(nullptr), prev(nullptr) {
    }
};

template<typename T>
bool compareTrees(Node<T> *a, Node<T> *b);

template<typename T>
bool breadthFirstSearch(Node<T> *head, T target);

template<typename T>
std::vector<T> graphBFS(const std::vector<std::vector<T> > &graph, T source, T target);

template<typename T>
bool depthFirstSearch(Node<T> *head, T target);

template<typename T>
std::vector<T> graphDFS(const std::vector<std::vector<std::pair<T, T> > > &graph, T source, T target);

template<typename T>
void dijkstraAlgorithm(T src, const std::vector<std::vector<std::pair<T, T> > > &graph);

template<typename T>
std::vector<T> preOrderTraversal(Node<T> *head);

int partition(std::vector<int> &arr, int lo, int hi);

void quickSort(std::vector<int> &arr, int lo, int hi);

#endif // GRAPH_AND_SEARCH_ALGORITHMS_H
