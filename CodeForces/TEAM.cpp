#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int count = 0;
    for(int i=0;i<n;i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        if(a+b+c > 1){
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
