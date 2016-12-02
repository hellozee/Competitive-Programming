#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> fees(n);
    for(int i=0;i<n;i++){
        std::cin >> fees[i];
    }
    std::vector<int>best(n,0);
    
    best[0] = fees[0];
    best[1] = fees[0]+fees[1];
    best[2] = fees[2] + std::max(fees[0],fees[1]);
    
    for(int i=3;i<n;i++){
        int a = best[i-1];
        int b = fees[i] + fees[i-1] + best[i-3];
        int c = fees[i] + best[i-2];
        best[i] = std::max(a,std::max(b,c));
        //std::cout << best[i] << ' ' << a <<' ' << b << ' ' << c << std::endl;
    }
    
    std::cout << best[n-1] << std::endl;
}
