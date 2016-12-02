#include <iostream>

int main(){
    long long a ,b,c;
    std::cin >> a >> b >> c;
    if(a+b < c){
        std::cout <<  2*b + 2*a << std::endl;
        return 0;
    }
    if(a+c < b){
        std::cout << 2*a + 2*c << std::endl;
        return 0;
    }
    if(b+c < a){
        std::cout << 2*b + 2*c << std::endl;
        return 0;
    }
    std::cout << a + b + c << std::endl;
    return 0;
}
