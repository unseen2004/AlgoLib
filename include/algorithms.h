#ifndef GRAPH_AND_SEARCH_ALGORITHMS_H
#define GRAPH_AND_SEARCH_ALGORITHMS_H

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

// Node for Trees and Graphs
template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* next;
    Node<T>* prev;

    Node(T x) : val(x), left(nullptr), right(nullptr), next(nullptr), prev(nullptr) {}
};

// Comparison Function
template <typename T>
bool compare(Node<T>* a, Node<T>* b);

// BFS Traversal for Trees
template <typename T>
bool BFS(Node<T>* head, T target);

// BFS on Graphs
template <typename T>
std::vector<T> bfs(const std::vector<std::vector<T>>& graph, T source, T target);

// DFS for Trees
template <typename T>
bool dfs(Node<T>* head, T target);

// DFS on Graphs
template <typename T>
std::vector<T> dfs(const std::vector<std::vector<std::pair<T, T>>>& graph, T source, T target);

// Dijkstra's Algorithm
template <typename T>
void dijkstra(T src, const std::vector<std::vector<std::pair<T, T>>>& graph);

// Pre-order Traversal
template <typename T>
std::vector<T> pre_order_search(Node<T>* head);

// QuickSort
int partition(std::vector<int>& arr, int lo, int hi);
void qs(std::vector<int>& arr, int lo, int hi);

#endif // GRAPH_AND_SEARCH_ALGORITHMS_H
