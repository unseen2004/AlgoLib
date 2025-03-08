
#include "../../include/Sort/TwoWayMergeSort.h"
#include <algorithm>

template <typename T>
void TwoWayMergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void TwoWayMergeSort<T>::sort(std::vector<T>& arr) {
    int n = arr.size();

    for (int currSize = 1; currSize < n; currSize *= 2) {
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = std::min(left + currSize - 1, n - 1);
            int right = std::min(left + 2 * currSize - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

template class TwoWayMergeSort<int>;
template class TwoWayMergeSort<double>;

