#include <iostream>
#include <vector>

int binaryS(const int &target,const std::vector<int> &arr,const int &size){
    int low =0;
    int high = size - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target ){
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    return low;
}

int main (){
    int n;
    std::cin >> n;
    std::vector<int>nums(n);
    int size=0;
    for(int i=0;i<n;i++){
        int key;
        std::cin >> key;
        int temp = binaryS(key,nums,size);
        nums[temp] = key;
        if(temp == size){
            size++;
        } 
    } 
    std::cout<< n-size << std::endl;
    return 0;
}
