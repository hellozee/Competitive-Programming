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
    k = (k/2)*2; //Odd number of transactions will be useless as we can only buy in the last transaction
                // thus rounding it to the nearest even, that is k-1 , if it is even than no changes will be made
                // a sheer piece of smartness , (always praise yourself)
    
    std::vector<std::vector<int> > stockTable(k+1,std::vector<int>(n+1)); //For keeping the records
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            stockTable[j][i] = 0;// You cant do a transaction if days are less than the transaction number
        }
    }
    for(int i=1;i<=k;i++){
        std::vector<int> stocks = stockTable[i-1];// Copying the vector for better readability
        for(int j=i;j<=n;j++){
            if(i%2 !=0){
                //Here we can only buy
                stockTable[i][j] = *std::max_element(stocks.begin()+i-1,stocks.begin()+j) - market[j-1];
                //We can only earn more profit when we can buy where the investment is less , for that we must also 
                //take into account of the previous max profit upto that day we made in the last transaction
                // -ve sign for we are buying , hence we are investing our money
            }else{
                //Here we can only sell
                stockTable[i][j] = *std::max_element(stocks.begin()+i-1,stocks.begin()+j) + market[j-1];
                //Time to earn profit , this one is easy , cause we can only earn the max profit if and only if
                //the investment is minimum , I used max element cause , the previous ones are negative numbers as 
                //last transaction we invested our money.
            }
        }
    }
    std::vector<int> lastTrans = stockTable[k];
    std::cout << *std::max_element(lastTrans.begin(),lastTrans.end()) << std::endl;
    //Surely this code can be optimized more but I will leave that as a excercise to you
    //Happy Coding
    return 0;
}
