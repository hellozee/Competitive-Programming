#include <iostream>
#include <vector>

#define NIL -1 //For readability

int n,k;
std::vector<int>B(701);
std::vector<int>V(701);
std::vector<std::vector<int> >hashTable(701,std::vector<int>(701,NIL));//For Memoization , speed baby

int solve(int left,int right){
    if(hashTable[left][right] != NIL){
        return hashTable[left][right];
    }
    if(left >= right){
        return 0;
    }
    int max = solve(left+1,right);//if we dont include the left , what will be the best?
    
    for(int i=left+1;i<=right;i++){
        if(B[left]+k == B[i]){
            int temp = solve(left+1,i-1) + solve(i+1,right) + V[left] + V[i];//If this is a well bracketed one,is
                                                                             //there any others inside it?
            max = std::max(temp,max);
        }
        
    }
    hashTable[left][right] = max;
    return max;
}

int main(){

    std::cin >> n >> k;
    for(int i=0;i<n;i++) std::cin >> V[i];
    for(int i=0;i<n;i++) std::cin >> B[i];

    std::cout << solve(0,n-1) << std::endl;

    return 0;
}
