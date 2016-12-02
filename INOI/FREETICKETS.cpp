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
    map[vertex] = 0; //Distance to the vertex itself is always 0
    for(int i=0;i<size;i++){
        if(i == vertex){
            continue;
        }
        if(graph[vertex][i] != NIL){
            distances a;
            a.index = i;
            a.dist = graph[vertex][i];
            heap.push(a);//If edge with the vertex is present then insert with the edge weight 
        }else{
            distances a;
            a.index = i;
            a.dist = INT_MAX;
            heap.push(a);//If not then push with infinity , I mean the maximum possible number
        }
    }
    visited[vertex] = true;//You are begining from it
    while(!heap.empty()){
        distances top = heap.top(); // Getting the smallest distance from the priority queue
        heap.pop();//throw it out
        int ind = top.index;
        int distance = top.dist;
        if(visited[ind]){
            continue;//if visited earlier , it means we have a smaller distance to it , lets continue
        }
        //std::cout << ind << ' ';
        map[ind] = distance;//The smallest distance possible
        visited[ind] = true;//We visited it
        for(int i=0;i<size;i++){
            if(graph[ind][i] != NIL && !visited[i]){
                distances a;
                a.index = i;
                //std::cout << ind << ' ' << distance << ' ';
                a.dist = graph[ind][i] + distance;
                if( a.dist < map[i]){
                    heap.push(a);//finding the vertexes connected to the smallest vertex we just poped from the heap
                }
            }
        }
    }
    //std::cout << std::endl;
    int ret = *std::max_element(map.begin(),map.end());//As it is a fully connected graph we will encounter each & every vertex
                                                       //and we will have distance of integral length , so no INT_MAXes possible
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
