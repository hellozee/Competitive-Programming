#include <iostream>
#include <vector>
#include <string>

bool possible(std::string target,std::string key){
    
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::string>words(n);
    std::vector<std::vector<bool> >graph(n,std::vector<bool>(n,false));
    for(int i=0;i<n;i++){
        std::cin >> words[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(possible(words[j],words[i])){
                graph[i][j] = true;
            }
        }
    }
    return 0;
}
