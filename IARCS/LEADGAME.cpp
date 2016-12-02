#include <iostream>
 
int main(){
    long long t,p=1,max=0,a=0,b=0;
    std::cin>>t;
    while(t--){
        int c,d;
        std::cin>>c>>d;
        a+=c;
        b+=d;
        if(max<a-b){
            p=1;
            max=a-b;
        }else if(max<b-a){
            p=2;
            max=b-a;
        }
    }
    std::cout<< p << " " << max << std::endl;
    return 0;
}   
