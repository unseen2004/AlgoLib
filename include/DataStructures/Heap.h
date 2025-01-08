#ifndef HEAP_H
#define HEAP_H

#include <vector>

template<typename T>
class Heap {
private:
    int length;
    std::vector<T> data;
    bool isMinHeap;

public:
    Heap(bool minHeap = true);
    ~Heap();
    void insert(T n);
    T deleteTop();

private:
    int parent(int idx) const;
    int leftChild(int idx) const;
    int rightChild(int idx) const;
    void heapifyUp(int idx);
    void heapifyDown(int idx);
    bool compare(T a, T b) const;
};

#endif // HEAP_H
