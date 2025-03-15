module;
import <vector>;
import <ranges>;
import <print>;
import <expected>;

export module MergeSort;
export template<typename T>
struct MergeSort {
    auto sort(std::vector<T>& data) -> std::expected<void, std::string> {
        if(!data.empty()) mergeSort(data, 0, (int)data.size()-1);
        return {};
    }
    auto mergeSort(std::vector<T>& data, int left, int right) -> void {
        if(left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(data, left, mid);
            mergeSort(data, mid + 1, right);
            merge(data, left, mid, right);
        }
    }
    auto merge(std::vector<T>& data, int left, int mid, int right) -> void {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<T> L(n1), R(n2);
        for(int i = 0; i < n1; ++i) L[i] = data[left + i];
        for(int j = 0; j < n2; ++j) R[j] = data[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2) {
            if((L[i] <=> R[j]) <= 0) {
                data[k++] = L[i++];
            } else {
                data[k++] = R[j++];
            }
        }
        while(i < n1) data[k++] = L[i++];
        while(j < n2) data[k++] = R[j++];
    }
};;