#include <iostream>
#include <vector>
/*
int main(){
    int n;
    std::cin >> n;
    std::vector<int>wealth(n,0);
    for(int i=0;i<n;i++){
        std::cin >> wealth[i];
        int rank = 1;
        for(int j=i;j>0;j--){
            if(wealth[j] < wealth[j-1]){
                rank = j+1;
                break;
            }else{
                int temp = wealth[j];
                wealth[j] = wealth[j-1];
                wealth[j-1] = temp;
            }
        }
        std::cout << rank << std::endl;
    }
    return 0;
}
*/
int main(){
    int n;
    std::cin >> n;
    std::vector<int>wealth(n,0);
    for(int i=0;i<n;i++){
        std::cin >> wealth[i];
    }
    for(int i=0;i<n;i++){
        int temp = wealth[i];
        int j = i-1;
        
        while(j+1 > 0 && wealth[j] < temp ){
            wealth[j+1] = wealth[j];
            --j;
        }
        wealth[j+1] = temp;
        std::cout << j+2 << std::endl;
    }
    return 0;
}
