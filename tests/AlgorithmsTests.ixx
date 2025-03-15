module;

import <iostream>;
import BloomFilter;
import FordFulkerson;
import GraphAlgorithms;
import KruskalMST;
import PrimMST;
import TreeAlgorithms;
import UnionFind;

export module AlgorithmsTests;
export namespace algorithmsTests {

auto testBloomFilter() -> void {
    std::cout << "Testing BloomFilter:\n";
    BloomFilter<int> bf(10, 3);
    bf.add(42);
    std::cout << "Might contain 42? " << (bf.mightContain(42) ? "Yes\n" : "No\n");
}

auto testFordFulkerson() -> void {
    std::cout << "\nTesting FordFulkerson:\n";
    FordFulkerson<int> ff(4);
    ff.addEdge(0, 1, 20);
    ff.addEdge(1, 2, 10);
    ff.addEdge(2, 3, 5);
    std::cout << "Max flow from 0 to 3: " << ff.maxFlow(0, 3) << "\n";
}

auto testGraphAlgorithms() -> void {
    std::cout << "\nTesting GraphAlgorithms:\n";
    std::vector<std::vector<int>> graph = {
        {0,1,1}, {1,0,1}, {1,1,0}
    };
    auto path = graphBFS(graph, 0, 2);
    std::cout << "BFS path from 0 to 2: ";
    for (auto &p : path) std::cout << p << " ";
    std::cout << "\n";
}

auto testKruskalMST() -> void {
    std::cout << "\nTesting KruskalMST:\n";
    std::vector<std::pair<int,std::pair<int,int>>> edges {
        {2,{0,1}}, {3,{1,2}}, {1,{0,2}}
    };
    auto mst = kruskalMST(edges, 3);
    std::cout << "Kruskal MST edges:\n";
    for (auto &e : mst) {
        std::cout << e.first << " - " << e.second << "\n";
    }
}

auto testPrimMST() -> void {
    std::cout << "\nTesting PrimMST:\n";
    std::vector<std::vector<std::pair<int,int>>> graph = {
        {{1,2}}, {{0,2},{2,3}}, {{1,3}}
    };
    PrimMST<int> mst(graph);
    mst.run();
    mst.printMST(std::cout);
}

auto testTreeAlgorithms() -> void {
    std::cout << "\nTesting TreeAlgorithms:\n";
    // Example usage: compareTrees, BFS, DFS, etc.
    // Detailed tests omitted for brevity
}

auto testUnionFind() -> void {
    std::cout << "\nTesting UnionFind:\n";
    UnionFind<int> uf(5);
    uf.unionSets(0, 1);
    uf.unionSets(3, 4);
    std::cout << "Find(1): " << uf.find(1) << "\n";
    std::cout << "Find(3): " << uf.find(3) << "\n";
}

auto runAll() -> void {
    testBloomFilter();
    testFordFulkerson();
    testGraphAlgorithms();
    testKruskalMST();
    testPrimMST();
    testTreeAlgorithms();
    testUnionFind();
}

} // namespace algorithmsTests