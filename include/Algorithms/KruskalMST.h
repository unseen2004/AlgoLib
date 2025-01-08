#ifndef KRUSKALMST_H
#define KRUSKALMST_H

#include <vector>
#include <utility>

template <typename W, typename T>
std::vector<std::pair<T, T>> kruskalMST(std::vector<std::pair<W, std::pair<T, T>>>& edges, T n);

#endif // KRUSKALMST_H
