#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <vector>

template<typename T>
class BucketSort {
public:
    void sort(std::vector<T>& data);

private:
    void insertionSort(std::vector<T>& bucket);
};

#endif // BUCKETSORT_H