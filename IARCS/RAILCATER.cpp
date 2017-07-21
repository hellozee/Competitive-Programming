#include <iostream>
#include <vector>

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int>profits(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        std::cin >> profits[i];
    }
    
    for(int i=0;i<k;i++){
        sum += profits[i];
    }
    
    int maxSofar = sum;
    int maxEnd = 0;
    
    for(int i=k;i<n;i++){
        sum += profits[i];
        maxEnd += profits[i-k];
        if(maxEnd < 0){
            sum -= maxEnd;
            maxEnd = 0;
        }
        if(sum > maxSofar){
            maxSofar = sum;
        }
    }
    
    std::cout << maxSofar << std::endl;
    
    return 0;
}
