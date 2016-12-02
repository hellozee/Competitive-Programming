#include <iostream>

int main(){
    int m ,n;
    std::cin >> m >> n;
    int dominoes = 0;
    
    while(n/2 > 0){
        dominoes += m;
        n -= 2;
        //std::cout << n << ' ' << dominoes << std::endl;
    }
    if(n==1){
        dominoes += m/2;
    }
    std::cout << dominoes << std::endl;
    return 0;
}
