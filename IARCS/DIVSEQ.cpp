#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>nums(n);
    for(int i=0;i<n;i++){
        std::cin >> nums[i];
    }
    std::vector<int>facs(n,1);
    int max = 0;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(facs[j] >= facs[i] && nums[i]%nums[j] == 0){
                facs[i] = facs[j]+1;
                if(facs[i] > max){
                    max = facs[i];
                }
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}
