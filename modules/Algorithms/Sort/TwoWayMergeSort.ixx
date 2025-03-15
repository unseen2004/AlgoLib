module;
import <vector>;
import <ranges>;
import <print>;
import <expected>;

export module TwoWayMergeSort;
export template<typename T>
struct TwoWayMergeSort {
    auto sort(std::vector<T>& arr) -> std::expected<void,std::string> {
        auto n=arr.size();
        for(auto currSize=1;currSize<n;currSize*=2) {
            for(auto left=0;left<n-1;left+=2*currSize) {
                auto mid=min(left+currSize-1,(int)n-1);
                auto right=min(left+2*currSize-1,(int)n-1);
                merge(arr,left,mid,right);
            }
        }
        return {};
    }
    auto merge(std::vector<T>& arr,int left,int mid,int right) -> void {
        auto [n1,n2]=std::pair{mid-left+1,right-mid};
        std::vector<T> L(n1),R(n2);
        for(auto i=0;i<n1;++i) L[i]=arr[left+i];
        for(auto j=0;j<n2;++j) R[j]=arr[mid+1+j];
        auto [i,j,k] = std::make_tuple(0, 0, left);
        while(i<n1&&j<n2) {
            if((L[i]<=>R[j])<=0) arr[k++]=L[i++];
            else arr[k++]=R[j++];
        }
        while(i<n1) arr[k++]=L[i++];
        while(j<n2) arr[k++]=R[j++];
    }
    auto min(int a,int b){return (a<b)?a:b;}
};