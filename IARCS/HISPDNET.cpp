//Solves for 70 , TLE for rest

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

int prims(std::vector<std::vector<int> >graph,int size,int vertex){
    std::priority_queue<distances>queue;
    std::vector<bool>visited(size);
    visited[vertex] = true;
    //visited[0] = true;
    int total = 0;
    for(int i=0;i<size;i++){
        if(graph[vertex][i]){
            distances a;
            a.index = i;
            a.dist = graph[1][i];
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
        total += edge;
        for(int i=0;i<size;i++){
            if(graph[ind][i] && !visited[i]){
                distances a;
                a.index = i;
                a.dist = graph[ind][i];
                queue.push(a);
            }
        }
    }
    
    return total;
}


int main(){
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
