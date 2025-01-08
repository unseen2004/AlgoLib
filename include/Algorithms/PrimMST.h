#ifndef PRIMMST_H
#define PRIMMST_H

#include <vector>
#include <iostream>
#include <queue>
#include <limits>

template <typename T>
class PrimMST {
private:
    std::vector<std::vector<std::pair<int, T>>> m_graph;
    std::vector<T> m_key;
    std::vector<int> m_parent;
    std::vector<bool> m_inMST;

public:
    PrimMST(const std::vector<std::vector<std::pair<int, T>>>& graph); // Constructor

    void run();
    void printMST(std::ostream& os); // Print the MST
};

#endif // PRIMMST_H
