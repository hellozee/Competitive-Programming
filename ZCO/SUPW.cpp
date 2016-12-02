#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>dutyTime(n);
    for(int i=0;i<n;i++){
        std::cin >> dutyTime[i];
    }
    std::vector<int>bestTime(n);
    bestTime[0] = dutyTime[0];
    bestTime[1] = dutyTime[1];
    bestTime[2] = dutyTime[2];
    for(int i=3;i<n;i++){
        bestTime[i] = dutyTime[i]+std::min(bestTime[i-1],std::min(bestTime[i-2],bestTime[i-3]));
    }
    std::cout << std::min(bestTime[n-1],std::min(bestTime[n-2],bestTime[n-3])) << std::endl;
    return 0;
}
