#include <iostream>
#include <vector>

long long maxPossible(int size){
    size++;
    long long ret = 0;
    int power = 1;
    for(int i=1;i<=size;i++){
        ret += i*power;
        power *= 10;
    }
    return ret;
}

bool magicNum(long long num){
    std::vector<bool>isNotUnique(10,false);
    while(num){
        if(isNotUnique[num%10] || num%10 == 0){
            return false;
        }
        isNotUnique[num%10] = true;
        num /= 10;
    }
    return true;
}

long long repFree(long long num,long long max){
    
    for(int i=num+1;i<=max;i++){
        if(magicNum(i)){
            return i;
            break;
        }
    }
}

int main(){
    long long n;
    std::cin >> n;
    int size = 0;
    long long temp = n;
    
    while(temp){
        size++;
        temp /= 10;
    }
    long long max = maxPossible(size);
    std::cout << repFree(n,max) << std::endl; 
}
