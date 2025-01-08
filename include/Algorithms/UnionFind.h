#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>
#include <algorithm>

template <typename T>
class UnionFind {
private:
    std::vector<T> m_parent;
    std::vector<T> m_rank;

public:
    UnionFind(T n);

    T find(T u);
    void unionSets(T u, T v);
};

#endif // UNIONFIND_H
