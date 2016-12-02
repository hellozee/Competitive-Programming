#include <iostream>

int main(){
    int n;
    std::cin >> n;
    unsigned long long f1 = 2,f2 = 1,fn =2, g2 = 1;
    
    for(int i=3;i<=n;i++){
        fn = f1 + f2 + 2 * g2;
        fn = fn%10000;
        g2 = g2 +f2;
        f2 = f1;
        f1 = fn;
    }
    
    std::cout << fn << std::endl;
    return 0;
}
