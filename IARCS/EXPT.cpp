//Still Incomplete

#include <iostream>
#include <vector>


int main(){
    int n;
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
    std::vector<int>parentTableFirst(n,-1);
    std::vector<int>parentTableSec(n,-1);    
    
    int max = 0;
    int x , y;
    //std::cout << "got here" << std::endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //std::cout << "got here" << std::endl;
            for(int k=i+1;k<n;k++){
                for(int l=j+1;l<n;l++){
                    //std::cout << k << ' ' << l << std::endl;
                    if(first[k]-first[i] == second[l]-second[j]){
                        if(table[i][j] <= table[k][l]){
                            table[k][l] = table[i][j] + 1;
                            if(table[k][l] > max){
                                max = table[k][l];
                                parentTableFirst[k] = i;
                                parentTableSec[l] = j;
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
    
    std::vector<int>sequenceFirst;
    std::vector<int>sequenceSec;
    
    while(parentTableFirst[x] != -1){
        sequenceFirst.push_back(first[x]);
        //std::cout << first[x] << std::endl;
        x = parentTableFirst[x];
    }
    sequenceFirst.push_back(first[x]);
    //std::cout << first[x];
    
    for(int i=max-1;i>=0;i--){
        std::cout << sequenceFirst[i] << ' ';
    }
    
    std::cout << std::endl;
    
    
    while(parentTableSec[y] != -1){
        sequenceSec.push_back(second[y]);
        y = parentTableSec[y];
    }
    sequenceSec.push_back(second[y]);
    
    for(int i=max-1;i>=0;i--){
        std::cout << sequenceSec[i] << ' ';
    }
    
    std::cout << std::endl;
    
    return 0;
}
