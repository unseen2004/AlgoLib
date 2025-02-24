#include "../../include/Sort/QuickSort.h"

template<typename T>
void QuickSort<T>::sort(std::vector<T>& data) {
    quickSort(data, 0, data.size() - 1);
}

template<typename T>
void QuickSort<T>::quickSort(std::vector<T>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

template<typename T>
int QuickSort<T>::partition(std::vector<T>& data, int low, int high) {
    T pivot = data[high];
    int i = (low - 1);

    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return (i + 1);
}
