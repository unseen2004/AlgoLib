#include "../../include/Algorithms/UnionFind.h"
#include "../../include/Algorithms/KruskalMST.h"


template <typename W, typename T>
std::vector<std::pair<T, T>> kruskalMST(std::vector<std::pair<W, std::pair<T, T>>>& edges, T n) {
    std::sort(edges.begin(), edges.end());
    UnionFind<T> uf(n);
    std::vector<std::pair<T, T>> mst;
    for (auto& [weight, edge] : edges) {
        T u = edge.first;
        T v = edge.second;
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst.push_back({u, v});
        }
    }
    return mst;
}

