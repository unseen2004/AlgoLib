cmake_minimum_required(VERSION 3.29)
project(AlgoLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(AlgoLib
        include/Algorithms/Node.h
        include/Algorithms/TreeAlgorithms.h
        src/Algorithms/TreeAlgorithms.cpp
        include/Algorithms/GraphAlgorithms.h
        src/Algorithms/GraphAlgorithms.cpp
        include/Algorithms/SortingAlgorithms.h
        src/Algorithms/SortingAlgorithms.cpp
        include/DataStructures/Node.h
        include/DataStructures/Trie.h
        include/DataStructures/LRU_Cache.h
        include/DataStructures/Heap.h
        include/DataStructures/LinkedList.h
        include/DataStructures/DoubleLinkedList.h
        src/DataStructures/Trie.cpp
        src/DataStructures/LRU_Cache.cpp
        src/DataStructures/Heap.cpp
        src/DataStructures/LinkedList.cpp
        src/DataStructures/DoubleLinkedList.cpp
        include/DataStructures/AVLTree.h
        src/DataStructures/AVLTree.cpp
        include/DataStructures/BTree.h
        src/DataStructures/BTree.cpp
        include/DataStructures/BST.h
        src/DataStructures/BST.cpp
        include/DataStructures/RedBlackTree.h
        src/DataStructures/RedBlackTree.cpp
        include/Algorithms/BloomFilter.h
        src/Algorithms/BloomFilter.cpp
        include/Algorithms/FordFulkerson.h
        src/Algorithms/FordFulkerson.cpp
        include/Algorithms/UnionFind.h
        src/Algorithms/UnionFind.cpp
        include/Algorithms/KruskalMST.h
        src/Algorithms/KruskalMST.cpp
        include/Algorithms/PrimMST.h
        src/Algorithms/PrimMST.cpp)
