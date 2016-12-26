#include <iostream>
#include <vector>

int main(){

    int n;
    std::cin >> n;
    std::vector<std::vector<bool> >graph(n,std::vector<bool>(n,false));
    std::vector<int>path(n);

    for(int i=0;i<n;i++){
        int m;
        std::cin >> m;
        while(m--){
            int temp;
            std::cin >> temp;
            temp--;
            graph[i][temp] = true;
        }
    }

    bool possible;
    path[0] = 0;
    for(int i=1;i<n;i++){
        int pos = -1;
        for(int j=0;j<i;j++){
            if(graph[i][path[j]]){
                pos = j;
                break;
            }
            if(j == i-1){
                pos = i;
            }
        }
        if(pos == -1){
            if(!graph[i][path[0]]){
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        for(int j=i;j>pos;j--){
            path[j] = path[j-1];
        }
        path[pos] = i;
    }

    std::cout << "YES" << std::endl;

    for(int i=0;i<n;i++){
        std::cout << (path[i]+1) << ' ';
    }
    std::cout << std::endl;

    return 0;
}
