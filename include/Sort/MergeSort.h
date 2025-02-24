#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<typename T>
class MergeSort {
public:
    void sort(std::vector<T>& data);

private:
    void mergeSort(std::vector<T>& data, int left, int right);
    void merge(std::vector<T>& data, int left, int mid, int right);
};

#endif // MERGESORT_H