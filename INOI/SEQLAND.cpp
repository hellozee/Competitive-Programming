#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool isRelative(std::vector<int> v1,std::vector<int>v2,int limit){
    int i = 1;
    int j = 1;
    int iMax = v1[0]+1;
    int jMax = v2[0]+1;
    int count = 0;
    while(i < iMax && j < jMax){
        if(v1[i] == v2[j]){
            count++;
            i++;
            if(count == limit){
                return true;
            }
        }else if(v1[i] < v2[j]){
            i++;
        }else{
            j++;
        }
    }
    return false;
}

int bfs(std::vector<std::vector<bool> >graph,int n){
    std::queue<int>q;
    q.push(0);
    std::vector<bool>visited(n);
    visited[0] = true;
    int famillies = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[a][i]){
                visited[i] = true;
                q.push(i);
                famillies++;
            }
        }
    }
    return famillies;
}

int main(){
    int n,m;
    std::ios_base::sync_with_stdio (false);
    std::cin >> n >> m;
    static std::vector<std::vector<int> >people(n);
    for(int i=0;i<n;i++){
        int m;
        std::cin >> m;
        people[i].resize(m+1);
        people[i][0] = m;//store the size in the first element of the vector
        for(int j=1;j<m+1;j++){
            std::cin >> people[i][j];
        }
        sort(people[i].begin()+1,people[i].end());// sorting for the binary search
    }
    std::vector<std::vector<bool> >graph(n,std::vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j != i){
                if(isRelative(people[i],people[j],m)){
                    graph[i][j] = true;
                }
            }
        }
    }
    int famillies = bfs(graph,n);
    std::cout << famillies+1 << std::endl;
    return 0;
}
