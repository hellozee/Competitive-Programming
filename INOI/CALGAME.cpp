#include <iostream>
#include <vector>

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int>square(n);
    k--;
    for(int i=0;i<n;i++){
        std::cin >> square[i];
    }
    std::vector<int>bestFirst(n,0);
    std::vector<int>bestSec(n,0);
    if(k != n-1){
        bestFirst[k+1] = square[k+1];
    }
    bestFirst[k] = 0;
    for(int i=k+2;i<n;i++){
        bestFirst[i] = square[i] + std::max(bestFirst[i-1],bestFirst[i-2]);
    }
    //std::cout << best1 << ' ' << pos << std::endl;
    bestSec[0] = square[0];
    bestSec[1] = square[1]+square[0];
    for(int i=2;i<n;i++){
        bestSec[i] = square[i] + std::max(bestSec[i-1],bestSec[i-2]);
        //std::cout << bestSec[i] << std::endl;
    }
    int best = std::max(bestSec[k-1],bestSec[k-2]);
    /*
    for(int i=0;i<n;i++){
        std::cout << bestFirst[i] << ' ';
    }
    std::cout << std::endl;
    for(int i=0;i<n;i++){
        std::cout << bestSec[i] << ' ';
    }
    std::cout << std::endl;
    */
    for(int i=k;i<n;i++){
        best = std::max(best,bestFirst[i]+std::max(bestSec[i-1],bestSec[i-2]));
    }
    //std::cout << best1 + std::max(bestSec[pos-1],bestSec[pos-2]) << std::endl;
    std::cout << best << std::endl;
    return 0;
}
