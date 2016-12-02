//Author  : Kuntal Majumder
//Problem : BUFFALOES

#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, char const* argv[])
{
    int n,k;
    std::cin >> n >> k;
    int market[n];
    for(int i=0;i<n;i++){
        std::cin >> market[i];
    }
    k = (k/2)*2;
    
    std::vector<std::vector<int> > stockTable(k+1,std::vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            stockTable[j][i] = 0;
        }
    }
    for(int i=1;i<=k;i++){
        std::vector<int> stocks = stockTable[i-1];
        for(int j=i;j<=n;j++){
            if(i%2 !=0){
                stockTable[i][j] = *std::max_element(stocks.begin()+i-1,stocks.begin()+j) - market[j-1];
            }else{
                stockTable[i][j] = *std::max_element(stocks.begin()+i-1,stocks.begin()+j) + market[j-1];
            }
        }
    }
    std::vector<int> lastTrans = stockTable[k];
    std::cout << *std::max_element(lastTrans.begin(),lastTrans.end()) << std::endl;
    return 0;
}
