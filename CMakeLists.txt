cmake_minimum_required(VERSION 3.29)
project(AlgoLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(AlgoLib
        include/Algorithms/TreeAlgorithms.hpp
        src/Algorithms/TreeAlgorithms.cpp
        include/Algorithms/GraphAlgorithms.hpp
        src/Algorithms/GraphAlgorithms.cpp
        src/Algorithms/SortingAlgorithms.cpp
        include/DataStructures/Node.hpp
        include/DataStructures/Trie.hpp
        include/DataStructures/LRU_Cache.hpp
        include/DataStructures/Heap.hpp
        include/DataStructures/LinkedList.hpp
        include/DataStructures/DoubleLinkedList.hpp
        src/DataStructures/Trie.cpp
        src/DataStructures/LRU_Cache.cpp
        src/DataStructures/Heap.cpp
        src/DataStructures/LinkedList.cpp
        src/DataStructures/DoubleLinkedList.cpp
        include/DataStructures/AVLTree.hpp
        src/DataStructures/AVLTree.cpp
        include/DataStructures/BTree.hpp
        src/DataStructures/BTree.cpp
        include/DataStructures/BST.hpp
        src/DataStructures/BST.cpp
        include/DataStructures/RedBlackTree.hpp
        src/DataStructures/RedBlackTree.cpp
        include/Algorithms/BloomFilter.hpp
        src/Algorithms/BloomFilter.cpp
        include/Algorithms/FordFulkerson.hpp
        src/Algorithms/FordFulkerson.cpp
        include/Algorithms/UnionFind.hpp
        src/Algorithms/UnionFind.cpp
        include/Algorithms/KruskalMST.hpp
        src/Algorithms/KruskalMST.cpp
        include/Algorithms/PrimMST.hpp
        src/Algorithms/PrimMST.cpp)
