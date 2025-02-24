#include "../../include/Sort/InsertionSort.h"

template<typename T>
void InsertionSort<T>::sort(std::vector<T>& data) {
    for (std::size_t i = 1; i < data.size(); ++i) {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}
