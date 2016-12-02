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
    std::vector<int>facs(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(facs[j] >= facs[i] && nums[i]%nums[j] == 0){
                facs[i] = facs[j]+1;
                //std::cout << facs[i] << std::endl;
            }
        }
    }
    sort(facs.begin(),facs.end() , std::greater<int>());
    std::cout << facs[0] << std::endl;
    return 0;
}
