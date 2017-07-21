#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define NIL -1

std::vector<std::vector<int> >graph(2001,std::vector<int>(2001,NIL));
std::vector<int>map(2001,INT_MAX);
std::vector<int>visited(2001,false);

struct pair{
    int index;
    int cost;
    bool operator<(const pair &p1) const{
        return cost > p1.cost;
    }
};

int dijkstra(int start){
    std::priority_queue<pair>heap;
    map[start] = 0;
    
    for(int i=0;i<2001;i++){
        if(graph[start][i] != NIL){
            pair temp;
            temp.index = i;
            temp.cost = graph[start][i];
            heap.push(temp);
            //std::cout << i << std::endl;
        }
    }
    
    visited[start] = true;
    
    while(!heap.empty()){
        pair top = heap.top();
        heap.pop();
        int vert = top.index;
        int cost = top.cost;
        if(visited[vert]){
            continue;
        }
        map[vert] = cost;
        visited[vert] = true;
        for(int i=0;i<2001;i++){
            if(graph[vert][i] != NIL){
                pair temp;
                temp.index = i;
                temp.cost = graph[vert][i] + cost;
                heap.push(temp);
            }
        }
    }
}

int main(){
    int n,start,end;
    std::cin >> n >> start >> end;
    
    for(int i=0;i<n;i++){
        int a,b,c;
        std::cin >> a >> c >> b;
        if(graph[a][b] == NIL || c < graph[a][b]){
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }
    
    dijkstra(start);
    
    if(map[end] == INT_MAX){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "YES" << std::endl;
        std::cout << map[end] << std::endl;
    }
}
