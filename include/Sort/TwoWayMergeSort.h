#ifndef TWO_WAY_MERGE_SORT_H
#define TWO_WAY_MERGE_SORT_H

#include <vector>

template <typename T>
class TwoWayMergeSort {
public:
    static void sort(std::vector<T>& arr);
    
private:
    static void merge(std::vector<T>& arr, int left, int mid, int right);
};

#endif // TWO_WAY_MERGE_SORT_H
