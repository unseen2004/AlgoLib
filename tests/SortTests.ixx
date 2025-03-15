module;

import BucketSort;
import InsertionSort;
import MergeSort;
import QuickSort;
import TwoWayMergeSort;
import <vector>;
import <print>;


export module SortTests;
export namespace sortTests {

template<typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& e : vec) {
        std::print("{} ", e);
    }
    std::print("\n");
}

export auto runAll() -> void {
    std::vector<int> v{5, 2, 9, 1, 5, 6};

    BucketSort<int> b;
    b.sort(v);
    printVector(v);

    v = {5, 2, 9, 1, 5, 6};
    InsertionSort<int> i;
    i.sort(v);
    printVector(v);

    v = {5, 2, 9, 1, 5, 6};
    MergeSort<int> m;
    m.sort(v);
    printVector(v);

    v = {5, 2, 9, 1, 5, 6};
    QuickSort<int> q;
    q.sort(v);
    printVector(v);

    v = {5, 2, 9, 1, 5, 6};
    TwoWayMergeSort<int>::sort(v);
    printVector(v);
}

}