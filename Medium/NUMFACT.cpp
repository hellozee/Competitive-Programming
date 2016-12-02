#include <iostream>
#include <map>
#include <cmath>

std::map<long long int,long long int>factors;

void findFactors(long long int num){
    long long int limit = sqrt(num);
    for(long long int i=2;i<=limit;i++){
        while(num%i == 0){
            factors[i]++;
            num /= i;
        }
    }
    if(num != 1){
        factors[num]++;
    }
}

int main(){
    long long int testCases;
    std::cin >> testCases;
    while(testCases--){
        long long int n;
        std::cin >> n;
        for(long long int i=0;i<n;i++){
            long long int temp;
            std::cin >> temp;
            findFactors(temp);
        }
        long long int total = 1;
        for(std::map<long long int,long long int>::iterator itr = factors.begin(); itr != factors.end(); ++itr){
            //std::cout << itr->second << std::endl;
            total *= itr->second+1;
        }
        std::cout << total << std::endl;
        factors.clear();
    }
    return 0;
}
