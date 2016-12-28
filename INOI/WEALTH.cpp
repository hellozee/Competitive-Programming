#include <iostream>
#include <vector>
#include <climits>

long long int dfs(const int &boss,const std::vector<std::vector<int> > &graph,const std::vector<long long int> &wealth,long long int money){
    long long int max = INT_MIN;
    money = std::max(wealth[boss],money);
    for(int i=0;i<graph[boss].size();i++){
        long long int temp = 0;
            temp = std::max(money - wealth[graph[boss][i]],dfs(graph[boss][i],graph,wealth,money));
            if(temp > max){
                max = temp;
            }
    }
    return max;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<long long int>wealth(n);
    std::vector<std::vector<int> >graph(n);
    for(int i=0;i<n;i++){
        std::cin >> wealth[i];
    }
    int boss = 0;
    for(int i=0;i<n;i++){
        int temp;
        std::cin >> temp;
        if(temp == -1){
            boss = i;
            continue;
        }
        temp--;
        graph[temp].push_back(i);
    } 
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout << graph[i][j] << ' ';
        }
        std::cout << std::endl;
    }*/
    std::cout << dfs(boss,graph,wealth,wealth[boss]) << std::endl;
    return 0;
}
