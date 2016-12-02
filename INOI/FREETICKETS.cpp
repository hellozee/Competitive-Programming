#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

#define NIL -1

typedef struct distances{
    int index;
    int dist;
    bool operator<(const distances &a) const{
        return dist > a.dist;
    }
}distances;

int dijkstra(std::vector<std::vector<int> >graph,int vertex,int size){
    std::vector<int>map(size,INT_MAX);
    std::priority_queue<distances>heap;
    std::vector<int>visited(size,false);
    map[vertex] = 0;
    for(int i=0;i<size;i++){
        if(i == vertex){
            continue;
        }
        if(graph[vertex][i] != NIL){
            distances a;
            a.index = i;
            a.dist = graph[vertex][i];
            heap.push(a);
        }else{
            distances a;
            a.index = i;
            a.dist = INT_MAX;
            heap.push(a);
        }
    }
    visited[vertex] = true;
    while(!heap.empty()){
        distances top = heap.top();
        heap.pop();
        int ind = top.index;
        int distance = top.dist;
        if(visited[ind]){
            continue;
        }
        //std::cout << ind << ' ';
        map[ind] = distance;
        visited[ind] = true;
        for(int i=0;i<size;i++){
            if(graph[ind][i] != NIL && !visited[i]){
                distances a;
                a.index = i;
                //std::cout << ind << ' ' << distance << ' ';
                a.dist = graph[ind][i] + distance;
                if( a.dist < map[i]){
                    heap.push(a);
                }
            }
        }
    }
    //std::cout << std::endl;
    int ret = *std::max_element(map.begin(),map.end());
    return ret;
}

int main(){
    int city,connections;
    std::cin >> city >> connections;
    std::vector<std::vector<int> >graph(city,std::vector<int>(city,NIL));//Adjacency matrix for storing the graph
    for(int i=0;i<connections;i++){
        int a , b;
        std::cin >> a >> b;
        a--;b--;
        std::cin >> graph[a][b];
        graph[b][a] = graph[a][b];
    }
    int max = 0;
    for(int i=0;i<city;i++){
        int highest = dijkstra(graph,i,city);//do dijkstra for each and every vertex
        if(highest > max){
            max = highest;
        }
    }
    std::cout << max << std::endl;
    return 0;
}
