#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void longestpalin(std::string str,int n){
    std::vector<std::vector<bool> > table(n,std::vector<bool>(n));//boolean table for keeping records of palindromes 
    
    int maxLength = 0;
    for(int i=0;i<n;i++){
        table[i][i] = true; // obviously every letter is palindrome of itself
    }
    
    int start = 0;
    
    for(int i=0;i<n-1;i++){
        if(str[i] == str[i+1]){
            table[i][i+1] = true; //two letters repeated is also a palindrome
            maxLength = 2;
            start = i;
        }
    }
    
    for(int k=3;k <= n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i + k - 1;
            if(table[i+1][j-1]&&str[i] == str[j]){
                //if 2 letters are same and the word/letter inbetween them is a palindrome
                //then the whole sequence is a palindrome
                table[i][j] = true; 
                if(k > maxLength){
                    maxLength = k;
                    start = i;
                }
            }
        }
    }
    std::cout << maxLength << std::endl;
    std::cout << str.substr(start,maxLength) << std::endl;
}

int main (int argc, char const* argv[])
{
    int n;
    std::cin >> n;
    std::string word;
    std::cin >> word;
    longestpalin(word,n);
    return 0;
}
