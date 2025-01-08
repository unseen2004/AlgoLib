#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <vector>
#include <queue>
#include <utility>

template<typename T>
std::vector<T> graphBFS(const std::vector<std::vector<T>> &graph, T source, T target);

template<typename T>
std::vector<T> graphDFS(const std::vector<std::vector<std::pair<T, T>>> &graph, T source, T target);

template<typename T>
void dijkstraAlgorithm(T src, const std::vector<std::vector<std::pair<T, T>>> &graph);

#endif // GRAPH_ALGORITHMS_H
