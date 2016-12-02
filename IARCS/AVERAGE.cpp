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
    sort(nums.begin(),nums.end());
    int count = 0;
    for(int i=1;i<n-1;i++){
        int lower = i-1;
        int upper = i+1; 
        if(nums[i] == nums[lower] || nums[i] == nums[upper]){
            //std::cout << nums[i] << ' ' << nums[lower] << ' ' << nums[upper] << std::endl;
            count++;
        }else{
        //std::cout << lower << ' ' << upper << ' ' << i << std::endl;     
        while(lower >= 0 && upper < n ){
            //std::cout << nums[lower] << ' ' << nums[upper] << std::endl;
            int average = nums[lower]+nums[upper];
            if(average == nums[i]*2){
                count++;
                //std::cout << nums[i] << ' ' << nums[lower] << ' ' << nums[upper] << std::endl;
                break;
            }
            if(average > nums[i]*2){
                --lower;
            }else{
                ++upper;
            }
        }}
    }
    std::cout << count << std::endl;
    return 0;
}
