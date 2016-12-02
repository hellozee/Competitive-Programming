#include <iostream>
#include <cmath>

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    if(num == 2){
        return true;
    }
    if(num%2 == 0){
        return false;
    }
    int stop = std::sqrt(num);
    for(int i=3;i<stop+1;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        long long int a ,b;
        std::cin >> a >> b;
        for(int i=a;i<=b;i++){
            if(isPrime(i)){
                std::cout << i << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
