#include "../../include/Algorithms/SortingAlgorithms.h"

int partition(std::vector<int> &arr, int lo, int hi) {
    const int pivot = arr[hi];
    int idx = lo - 1;
    for (int i = lo; i < hi; ++i) {
        if (arr[i] <= pivot) {
            ++idx;
            std::swap(arr[i], arr[idx]);
        }
    }
    ++idx;
    std::swap(arr[hi], arr[idx]);
    return idx;
}

void quickSort(std::vector<int> &arr, int lo, int hi) {
    if (lo >= hi) return;
    int pivotIdx = partition(arr, lo, hi);
    quickSort(arr, lo, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, hi);
}
