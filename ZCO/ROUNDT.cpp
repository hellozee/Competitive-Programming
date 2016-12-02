#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>knights(n);
    for(int i=0;i<n;i++){   
        std::cin >> knights[i];
    }
    
    std::vector<int>minCost(n);
    minCost[0] = knights[0];
    minCost[1] = knights[1];
    minCost[2] = std::min(knights[1],knights[2]);
    
    for(int i=3;i<n;i++){
        minCost[i] = knights[i]+std::min(minCost[i-1],minCost[i-2]);
    }
    
    int withArthur = std::min(minCost[n-1],minCost[n-2]) + knights[0];
    
    minCost[0] = knights[0];
    minCost[1] = std::min(knights[1],knights[0]);
    
    for(int i=2;i<n-1;i++){
        minCost[i] = knights[i]+std::min(minCost[i-1],minCost[i-2]);
    }
    
    int withoutArthur = std::min(minCost[n-2],minCost[n-3]) + knights[n-1];
    
    if(withArthur < withoutArthur){
        std::cout << withArthur << std::endl;
    }else{
        std::cout << withoutArthur << std::endl;
    }
    
    return 0;
}
