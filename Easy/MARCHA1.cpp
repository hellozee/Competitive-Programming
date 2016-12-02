#include <iostream>
#include <algorithm>
#include <vector>

int power(int n){
    int ret = 1;
    for(int i =0;i<n;i++){
        ret = ret * 2;
    }
    return ret;
}


int main(){
    int testCases;
    std::cin >> testCases;
    while(testCases--){
        int n ,m;
        std::cin >> n >> m;
        if(n>20){
            n = 20;
        }
        int notes[n];
        for(int i=0;i<n;i++){
            int cases;
            std::cin >> cases;
            if(cases > 1000){
                cases = 1000;
            }
            notes[i] = cases;
        }
        std::sort(notes,notes+n,std::greater<int>());
        int sum = 0;
        for(int i=0;i<power(n);i++){
            sum = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    sum+=notes[j];
            }
            if(sum == m){
                std::cout << "Yes" << std::endl;
                break;
            }
        }
        if(sum != m){
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
