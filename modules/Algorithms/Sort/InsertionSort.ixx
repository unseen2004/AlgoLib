module;
import <vector>;
import <ranges>;
import <print>;
import <expected>;

export module InsertionSort;
export template<typename T>
struct InsertionSort {
    auto sort(std::vector<T>& data) -> std::expected<void,std::string> {
        for(auto i=1UL;i<data.size();++i) {
            auto key=data[i];
            auto j=(int)i-1;
            while(j>=0&&(data[j]<=>key)>0) {
                data[j+1]=data[j];
                j--;
            }
            data[j+1]=key;
        }
        return {};
    }
};