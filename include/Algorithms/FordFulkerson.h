#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <vector>
#include <queue>
#include <limits>
#include <iostream>

template <typename FlowType>
class FordFulkerson {
private:
    int m_numVertices;
    std::vector<std::vector<FlowType>> m_capacity;
    std::vector<std::vector<FlowType>> m_residual;

public:
    FordFulkerson(int numVertices);

    void addEdge(int u, int v, FlowType capacity);
    FlowType maxFlow(int source, int sink);
    void minCut(int source);

private:
    bool bfs(int source, int sink, std::vector<int>& parent);
};

#endif // FORDFULKERSON_H
