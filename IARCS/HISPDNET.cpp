#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef struct distances{
    int index;
    int dist;
    bool operator<(const distances &a) const{
        return dist > a.dist;
    }
}distances;

int prims(const std::vector<std::vector<int> > &graph,const int &size,const int &vertex){
    std::priority_queue<distances>queue;
    std::vector<bool>visited(size,false);
    std::vector<int>map(size,INT_MAX);
    visited[vertex] = true;
    map[vertex] = 0;
    //visited[0] = true;
    int total = 0;
    for(int i=0;i<size;i++){
        if(graph[vertex][i]){
            distances a;
            a.index = i;
            a.dist = graph[1][i];
            map[i] = a.dist;
            queue.push(a);
        }else{
            distances a;
            a.index = i;
            a.dist = INT_MAX;
            queue.push(a);
        }
    }
    while(!queue.empty()){
        distances temp = queue.top();
        queue.pop();
        int ind = temp.index;
        int edge = temp.dist;
        if(visited[ind]){
            continue;
        }
        visited[ind] = true;
        map[ind] = edge;
        total += edge;
        for(int i=0;i<size;i++){
            if(graph[ind][i] < map[i] && !visited[i]){
                distances a;
                a.index = i;
                a.dist = graph[ind][i];
                map[i] = a.dist;
                queue.push(a);
            }
        }
    }
    
    return total;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::vector<int> >graph(n,std::vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> graph[i][j];
        }
    }
    /*int min = INT_MAX;
    for(int i=0;i<n;i++){
        int temp = prims(graph,n,i);
        if(temp < min){
            min = temp;
        }
    }*/
    std::cout << prims(graph,n,0) << std::endl;
    return 0;
}
