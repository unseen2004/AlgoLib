module;
import <vector>;
import <ranges>;
import <print>;
import <expected>;

export module BucketSort;
export template<typename T>
struct BucketSort {
    auto sort(std::vector<T>& data) -> std::expected<void,std::string> {
        if(data.empty()) return {};
        auto maxValue=data[0],minValue=data[0];
        for(auto& v:data) {
            if((v<=>maxValue)>0) maxValue=v;
            if((v<=>minValue)<0) minValue=v;
        }
        auto n=data.size();
        std::vector<std::vector<T>> buckets(n);
        for(auto& v:data) {
            auto idx=(int)((v-minValue)/(maxValue-minValue+1.0)*n);
            buckets[idx].push_back(v);
        }
        data.clear();
        for(auto& b:buckets) {
            insertionSort(b);
            for(auto& x:b) data.push_back(x);
        }
        return {};
    }
    auto insertionSort(std::vector<T>& b) {
        for(auto i=1UL;i<b.size();++i) {
            auto key=b[i];
            auto j=(int)i-1;
            while(j>=0&&(b[j]<=>key)>0) {
                b[j+1]=b[j];
                j--;
            }
            b[j+1]=key;
        }
    }
};