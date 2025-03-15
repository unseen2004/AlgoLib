cmake_minimum_required(VERSION 3.26)
project(AlgoLib_2_0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

# Enable modules for GCC
add_compile_options(-fmodules-ts)

# Create module library
add_library(AlgoLib)

# Use FILE_SET for modules
target_sources(AlgoLib
    PRIVATE
    FILE_SET CXX_MODULES FILES
        modules/DataStructures/Node.ixx
        modules/DataStructures/Queue.ixx
        modules/DataStructures/AVLTree.ixx
        modules/DataStructures/BST.ixx
        modules/DataStructures/BTree.ixx
        modules/DataStructures/DoubleLinkedList.ixx
        modules/DataStructures/Heap.ixx
        modules/DataStructures/LinkedList.ixx
        modules/DataStructures/LRU_Cache.ixx
        modules/DataStructures/RedBlackTree.ixx
        modules/DataStructures/Stack.ixx
        modules/DataStructures/Trie.ixx
        modules/Algorithms/Sort/BucketSort.ixx
        modules/Algorithms/Sort/InsertionSort.ixx
        modules/Algorithms/Sort/MergeSort.ixx
        modules/Algorithms/Sort/QuickSort.ixx
        modules/Algorithms/Sort/TwoWayMergeSort.ixx
        modules/Algorithms/BloomFilter.ixx
        modules/Algorithms/GraphAlgorithms.ixx
        modules/Algorithms/FordFulkerson.ixx
        modules/Algorithms/KruskalMST.ixx
        modules/Algorithms/PrimMST.ixx
        modules/Algorithms/TreeAlgorithms.ixx
        modules/Algorithms/UnionFind.ixx
)

# Create test module files
add_library(AlgoLib_TestModules OBJECT
    tests/DataStructuresTests.ixx
    tests/SortTests.ixx
    tests/GraphAlgorithmsTests.ixx
)

target_compile_options(AlgoLib_TestModules PRIVATE -fmodules-ts)
target_link_libraries(AlgoLib_TestModules PRIVATE AlgoLib)

# Create test executable
add_executable(AlgoLib_Tests tests/main.cpp)
target_compile_options(AlgoLib_Tests PRIVATE -fmodules-ts)
target_link_libraries(AlgoLib_Tests PRIVATE AlgoLib AlgoLib_TestModules)

# Testing
enable_testing()
add_test(NAME AlgoLib_Tests COMMAND AlgoLib_Tests)