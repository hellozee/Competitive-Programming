#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>nums(n);
    for(int i=0;i<n;i++){
        std::cin >> nums[i];
    }
    int max = 0;
    for(int i=0;i<n;i++){
        nums[i] += i+1;
        if(nums[i] > max){
            max = nums[i];
        }
    }
    std::cout << max << " ";
    int count = 1;
    for(int i = n-1;i>0;i--){
        nums[i] -= n;
        std::cout << *std::max_element(nums.begin(),nums.end())+count << " ";
        count++;
    }
    std::cout << std::endl;
    return 0;
}
