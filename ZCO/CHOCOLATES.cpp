#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>chocs(n);
    for(int i=0;i<n;i++){
        std::cin >> chocs[i];
    }
    std::vector<int>best(n);
    best[0] = chocs[0];
    best[1] = std::max(chocs[0],chocs[1]);
    for(int i=2;i<n;i++){
        best[i] = std::max(best[i-1],best[i-2]+chocs[i]);
        //std::cout << best[i] << std::endl;
    }
    std::cout << std::max(best[n-1],best[n-2]) << std::endl;
    return 0;
}
