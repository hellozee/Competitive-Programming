#include <iostream>

int main(){
    int testCases;
    std::cin >> testCases;
    while(testCases--){
        int n;
        std::cin >> n;
        int root = 0;
        int id,sum;
        bool first = true,broken = false;
        while(n--){
            if(first){
                std::cin >> id;
                if(id == 0){
                    std::cout << n+1 << std::endl;
                    broken = true;
                    break;
                }
                first = false;
                std::cin >> sum;
            }else{
                std::cin>> id >> sum;
            }
            root += id - sum;
        }
        if(!broken){
            std::cout << root << std::endl;
        }
    }
    return 0;
}
