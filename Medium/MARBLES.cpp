#include <iostream>

long long int choose(long long int n, long long int k){
    if(k > n/2){
        k = n - k;
    }
    long long int result = 1;
    for(int i=1;i<=k;i++){
        result *= (n-k+i);
        result /= i;
        //std::cout << result << ' ' << (n-i+1) << ' ' << i << std::endl;
    }
    return result;
}

int main(){
    int testCases;
    std::cin >> testCases;
    for(int i=0;i<testCases;i++){
        long long int n,k;
        std::cin >> n >> k;
        std::cout << choose(n-1,n-k) << std::endl;
    }
    return 0;
}
