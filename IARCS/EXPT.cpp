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
    std::vector<std::vector<int> >firstMat(n,std::vector<int>(n));
    std::vector<std::vector<int> >secMat(n,std::vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            firstMat[j][i] = first[0][i] - first[0][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            secMat[j][i] = second[0][i] - second[0][j];
        }
    }
    
    return 0;
}
