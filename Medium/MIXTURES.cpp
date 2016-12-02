#include <iostream>
#include <vector>
#include <climits>

int main(){
    int n;
    while(std::cin >> n && !std::cin.eof()){
        std::vector<int>mixtures(n);
        std::vector<std::vector<int> >sums(n,std::vector<int>(n,0));
        std::vector<std::vector<int> >smoke(n,std::vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            std::cin >> mixtures[i];
            sums[i][i] = mixtures[i];
        }
        
        for(int i=1;i<n;i++){
            for(int j = 0 ;j<i;j++){
                sums[j][i] = (mixtures[i] + mixtures[j])%100; 
            }
        }
        
        
    }
    return 0;
}
