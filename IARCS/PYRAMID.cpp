#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    int n;
    std::cin >> n;
    std::vector<int>sizes(n);
    for(int i=0;i<n;i++){
        int a,b;
        std::cin >> a >> b;
        if(a>b){
            sizes[i] = b;
        }else{
            sizes[i] = a;
        }
    }
    
    sort(sizes.begin(),sizes.end());
    //std::cout << std::endl;
    int count=0;

    for(int i=0;i<n;i++){
        if(count+1 <= sizes[i]){
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
