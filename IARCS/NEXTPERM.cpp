#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


int main(){
    int n ,k;
    std::cin >> n >> k;
    while(k--){
        int number[n];
        for(int i=0;i<n;i++){
            std::cin >> number[i];
        }
        int iPos , jPos;
        for(int i = n-2;i>=0;i--){
            if(number[i] < number[i+1]){
                iPos = i;
                break;
            }
        }
        for(int i = n-1;i>iPos;i--){
            if(number[i] > number[iPos]){
                jPos = i;
                break;
            }
        }
        std::swap(number[iPos],number[jPos]);
        for(int i=0;i<=iPos;i++){
            std::cout << number[i] << ' ';
        }
        for(int i=n-1;i>iPos;i--){
            std::cout << number[i] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
