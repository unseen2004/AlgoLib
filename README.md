# C++ Algorithms & Data Structures Library

<p align="center">
  <img src="https://img.shields.io/badge/Library-C++20-blue?style=for-the-badge" alt="C++20" />
  <img src="https://img.shields.io/badge/CMake-3.20+-blue?style=for-the-badge" alt="CMake" />
</p>

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Directory Structure](#directory-structure)
  - [Default Branch (Header-only)](#default-branch-header-only)
  - [Modules Branch (C++20 Modules)](#modules-branch-c20-modules)
- [Branches](#branches)
- [Build & Installation](#build--installation)
- [Testing](#testing)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

---

## Overview
This repository provides a comprehensive C++ library implementing various algorithms and data structures. It is designed with flexibility in mind and offers two versions:
- **Default Branch:** Traditional header-only implementation using `.hpp` files.
- **Modules Branch:** Modern C++20 module-based implementation using `.ixx` files.

## Features
- **Algorithms:**  
  - Bloom Filter  
  - Ford Fulkerson  
  - Graph Algorithms  
  - Minimum Spanning Trees (Kruskal, Prim)  
  - Sorting Algorithms: Bucket, Insertion, Merge, Quick, Two-Way Merge  
  - Tree Algorithms  
  - Union-Find
- **Data Structures:**  
  - AVL Tree  
  - Binary Search Tree (BST)  
  - B-Tree  
  - Doubly Linked List  
  - Heap  
  - Linked List  
  - LRU Cache  
  - Queue  
  - Red-Black Tree  
  - Stack  
  - Trie

---

## Directory Structure

### Default Branch (Header-only)
```
.
├── CMakeLists.txt
├── include
│   ├── Algorithms
│   │   ├── BloomFilter.hpp
│   │   ├── FordFulkerson.hpp
│   │   ├── GraphAlgorithms.hpp
│   │   ├── KruskalMST.hpp
│   │   ├── PrimMST.hpp
│   │   ├── Sort
│   │   │   ├── BucketSort.hpp
│   │   │   ├── InsertionSort.hpp
│   │   │   ├── MergeSort.hpp
│   │   │   ├── QuickSort.hpp
│   │   │   └── TwoWayMergeSort.hpp
│   │   ├── TreeAlgorithms.hpp
│   │   └── UnionFind.hpp
│   └── DataStructures
│       ├── AVLTree.hpp
│       ├── BST.hpp
│       ├── BTree.hpp
│       ├── DoubleLinkedList.hpp
│       ├── Heap.hpp
│       ├── LinkedList.hpp
│       ├── LRU_Cache.hpp
│       ├── Node.hpp
│       ├── Queue.hpp
│       ├── RedBlackTree.hpp
│       ├── Stack.hpp
│       └── Trie.hpp
├── main_test
└── tests
    ├── main_test.cpp
    ├── test_algorithms.hpp
    ├── test_datastructures.hpp
    └── test_sorting.hpp
```

### Modules Branch (C++20 Modules)
```
.
├── CMakeLists.txt
├── modules
│   ├── Algorithms
│   │   ├── BloomFilter.ixx
│   │   ├── FordFulkerson.ixx
│   │   ├── GraphAlgorithms.ixx
│   │   ├── KruskalMST.ixx
│   │   ├── PrimMST.ixx
│   │   ├── Sort
│   │   │   ├── BucketSort.ixx
│   │   │   ├── InsertionSort.ixx
│   │   │   ├── MergeSort.ixx
│   │   │   ├── QuickSort.ixx
│   │   │   └── TwoWayMergeSort.ixx
│   │   ├── TreeAlgorithms.ixx
│   │   └── UnionFind.ixx
│   └── DataStructures
│       ├── AVLTree.ixx
│       ├── BST.ixx
│       ├── BTree.ixx
│       ├── DoubleLinkedList.ixx
│       ├── Heap.ixx
│       ├── LinkedList.ixx
│       ├── LRU_Cache.ixx
│       ├── Node.ixx
│       ├── Queue.ixx
│       ├── RedBlackTree.ixx
│       ├── Stack.ixx
│       └── Trie.ixx
└── tests
    ├── AlgorithmsTests.ixx
    ├── DataStructuresTests.ixx
    ├── main.cpp
    └── SortTests.ixx
```

---

## Branches
- **Default Branch:**  
  Contains the header-only implementations (`.hpp` files) in the `include/` directory.
- **Modules Branch:**  
  Contains modern C++20 module implementations (`.ixx` files) in the `modules/` directory.

Switch between branches using:
```bash
git checkout modules   # For modules branch
git checkout main      # For default branch
```

## Build & Installation
This project uses CMake for configuration and building.

### Clone the Repository:
```bash
git clone https://github.com/unseen2004/YourRepoName.git
cd YourRepoName
```

### Checkout the Desired Branch:
For header-only implementation:
```bash
git checkout main
```
For module implementation:
```bash
git checkout modules
```

### Create a Build Directory and Configure:
```bash
mkdir build && cd build
cmake ..
```

### Build the Project:
```bash
cmake --build .
```

## Testing
Unit tests are provided to ensure the correctness of the library.

For the default branch, run:
```bash
./main_test
```

For the modules branch, execute the compiled test executable (usually `main` in the `tests/` folder).

## Usage
To use the library in your own projects, simply include the appropriate headers or modules.

### Default Branch (Header-only):
```cpp
#include "Algorithms/BloomFilter.hpp"
#include "DataStructures/AVLTree.hpp"
```

### Modules Branch (C++20 Modules):
```cpp
import Algorithms.BloomFilter;
import DataStructures.AVLTree;
```

---


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
