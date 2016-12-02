#include <iostream>

/* Problem 1
int main(){
    int sum = 0;
    for(int i=1;i<1000;i++){
        if(i%15==0){
            sum += i;
        }else if(i%5 == 0){
            sum += i;
        }else if(i%3 == 0){
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}
*/
/* Problem 2
int main(){
    long long int sum = 0;
    int f1=1,f2=1,fn=0;
    for(long long int i=0;i<4000000;i++){
        fn = f1 + f2;
        if(fn > 4000000){
            break;
        }
        f1 = f2;
        f2 = fn;
        if(fn%2 == 0){
            sum += fn;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
*/
/* Problem 3
int main(){
    long long int num = 600851475143;
    int divisor = 2;
    int largestFact = 0;
    while(divisor * divisor <= num ){
        if(num % divisor == 0){
            largestFact = divisor;
            num = num/divisor;
        }else{
            divisor++;
        }
    }
    if(num > divisor){
        largestFact = num;
    }
    std::cout << largestFact << std::endl;
    return 0;
}*/

int main(){
    int start = 997799;
    int stop = 100001;
    while(start > stop){
        
    }
    return 0;
}


