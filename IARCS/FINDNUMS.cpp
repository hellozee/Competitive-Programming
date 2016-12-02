#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

std::vector<int>factors(4,0);

int findFacs(int sum,int product,int facs,int index){
    if(facs == 1){
        if( product == sum){
            factors[index] = product;
            return 1;
        }else{
            return 0;
        }
    }
    int max = sqrt(product);
    for(int i=1;i<=max;i++){
        if(product%i == 0){
            factors[index] = i;
            if(findFacs(sum - i,product/i,facs-1,index+1)){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int sum , product,facs;
    std::cin>> sum >> product >> facs;
    if(findFacs(sum,product,facs,0)){
        if(std::find(factors.begin(),factors.end(),1) != factors.end()){
            for(int i=facs;i>0;i--){
                std::cout << factors[i-1] << " ";
            }
        }else{
            for(int i=0;i<facs;i++){
                std::cout << factors[i] << " ";
            }
        }
        std::cout << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}
