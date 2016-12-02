#include <iostream>
#include <cmath>

long long int findoddPalin(long long int half,int size,long long int num){
    long long int reverse = 0;
    int i = 100,j=pow(10,(size/2)-1);
    //std::cout << reverse << ' ' << half << std::endl;
    do{
        reverse += j*((half%i)/(i/10));
        //std::cout << reverse << ' ' << i << ' ' << j << std::endl;
        i *= 10; j /= 10;
    }while((half*10)/i > 0);
    long long int total = half*pow(10,size/2) + reverse;
    //std::cout << total << std::endl;
    //std::cout << reverse << std::endl;
    if(total > num){
        return total;
    }else{
        half++;
        return findoddPalin(half,size,num);
    }
}

long long int findevenPalin(long long int half,int size,long long int num){
    long long int reverse = 0;
    int i = 10,j=pow(10,(size/2)-1);
    //std::cout << reverse << ' ' << half << std::endl;
    do{
        reverse += j*((half%i)/(i/10));
        //std::cout << reverse << ' ' << i << ' ' << j << std::endl;
        i *= 10; j /= 10;
    }while((half*10)/i > 0);
    long long int total = half*pow(10,size/2) + reverse;
    //std::cout << total << std::endl;
    //std::cout << reverse << std::endl;
    if(total > num){
        return total;
    }else{
        half++;
        return findevenPalin(half,size,num);
    }
}

void findNearest(long long int number){
    long long int num = number;
    int size = 0;
    while(num){
        size++;
        num /= 10;
    }
    if(size%2){
        long long int palin = findoddPalin(number/(pow(10,size/2)),size,number);
        std::cout << palin << std::endl;
    }else{
        long long int palin = findevenPalin(number/(pow(10,size/2)),size,number);
        std::cout << palin << std::endl;
    }
}
int main(){
    int n;
    std::cin >> n;
    while(n--){
        long long int num;
        std::cin >> num;
        findNearest(num);
        //std::cout << "got here" << std::endl;
    }
    return 0;
}
