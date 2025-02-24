#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

template<typename T>
class QuickSort {
public:
    void sort(std::vector<T>& data);

private:
    void quickSort(std::vector<T>& data, int low, int high);
    int partition(std::vector<T>& data, int low, int high);
};

#endif // QUICKSORT_H
