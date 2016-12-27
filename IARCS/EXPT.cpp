#include <iostream>
#include <vector>


int main(){
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    std::vector<int>first(n);
    std::vector<int>second(n);
    for(int i=0;i<n;i++){
        std::cin >> first[i];
    }
    
    for(int i=0;i<n;i++){
        std::cin >> second[i];
    }
    
    std::vector<std::vector<int> >table(n,std::vector<int>(n,1));
    std::vector<std::vector<int> >parentTableFirst(n,std::vector<int>(n,-1));
    std::vector<std::vector<int> >parentTableSec(n,std::vector<int>(n,-1));    
    
    int max = 0;
    int x , y;
    //std::cout << "got here" << std::endl;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            //std::cout << "got here" << std::endl;
            for(int k=i-1;k>=0;k--){
                for(int l=j-1;l>=0;l--){
                    //std::cout << k << ' ' << l << std::endl;
                    if(first[k]-first[i] == second[l]-second[j]){
                        if(table[k][l] <= table[i][j] ){
                            table[k][l] = table[i][j] + 1;
                            parentTableFirst[k][l] = i;
                            parentTableSec[k][l] = j;
                            if (table[k][l] > max ||(table[k][l] == max && (k < x ||(k == x && l < y)))) {
                                max = table[k][l];
                                x = k;
                                y = l;
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    std::cout << max << std::endl;
    
    int xCopy = x;
    int yCopy = y;
    
    for(int i=0;i<max;i++){
        int temp = xCopy;
        std::cout << first[xCopy] << ' ';
        xCopy = parentTableFirst[xCopy][yCopy];
        yCopy = parentTableSec[temp][yCopy];
    }
    std::cout << std::endl;
    
    for(int i=0;i<max;i++){
        int temp = x;
        std::cout << second[y] << ' ';
        x = parentTableFirst[x][y];
        y = parentTableSec[temp][y];
    }
    std::cout << std::endl;
    /*
    while(parentTableFirst[x] != -1){
        std::cout << first[x] << ' ';
        x = parentTableFirst[x];
    }
    std::cout << first[x] << std::endl;
    
    while(parentTableSec[y] != -1){
        std::cout << second[y] << ' ';
        y = parentTableSec[y];
    }
    std::cout << second[y] << std::endl;*/
    
    return 0;
}
