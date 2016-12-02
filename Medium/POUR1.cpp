#include <iostream>

int gcd(int a ,int b){
    while(!b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(){
    int testCases;
    std::cin >> testCases;
    while(testCases--){
        int vsl1 ,vsl2 , vsl3;
        std::cin >> vsl1 >> vsl2 >> vsl3;
        if(vsl1 == vsl3 || vsl2 == vsl3){
            std::cout << '1' << std::endl;
            continue;
        }
        if(vsl3 > vsl1 && vsl3 > vsl2){
            std::cout << "-1" << std::endl;
            continue;
        }
        if(vsl3 == 0){
            std::cout << '0' << std::endl;
            continue;
        }
        int hcf = gcd(vsl1,vsl2);
        if(!vsl3%hcf){
            std::cout << "-1" << std::endl;
        }
        int steps = solve(vsl1,vsl2,vsl3);
    }
    return 0;
}
