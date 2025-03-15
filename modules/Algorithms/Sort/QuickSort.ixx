module;
import <vector>;
import <ranges>;
import <print>;
import <expected>;

export module QuickSort;
export template<typename T>
struct QuickSort {
    auto sort(std::vector<T>& data) -> std::expected<void, std::string> {
        if(!data.empty()) quickSort(data, 0, (int)data.size()-1);
        return {};
    }
    auto quickSort(std::vector<T>& data, int low, int high) -> void {
        if(low < high) {
            int pi = partition(data, low, high);
            quickSort(data, low, pi-1);
            quickSort(data, pi+1, high);
        }
    }
    auto partition(std::vector<T>& data, int low, int high) -> int {
        T pivot = data[high];
        int i = low - 1;
        for(int j = low; j < high; ++j) {
            if((data[j] <=> pivot) < 0) {
                i++;
                swap(data[i], data[j]);
            }
        }
        swap(data[i+1], data[high]);
        return i+1;
    }
    auto swap(T& a, T& b) -> void {
        T temp = a;
        a = b;
        b = temp;
    }
};