#include <iostream>

int exp(int power,int modulo,int num=2){
    //std::cout << power << std::endl;
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return num;
    }
    if(power%2){
        return (long long) num * exp((power-1)/2,modulo,(long long)num*num%modulo) % modulo;
    }else{
        return exp(power/2,modulo,(long long)num*num%modulo) % modulo;
    }
}

int find(int length,int modulo){
    int count = 0;
    for(int i = 1;i<=length/2;i++){
        if(length%i == 0){
            count += exp(i,modulo) - find(i,modulo) + modulo;
            count %= modulo;
        }
    }
    return count;
}

int main(){
    int length,modulo;
    std::cin >> length >> modulo;
    int total = exp(length,modulo);
    int Periodic = find(length,modulo);
    std::cout << (total-Periodic+modulo)%modulo << std::endl;
    return 0;
}
