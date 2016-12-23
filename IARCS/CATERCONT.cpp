#include <iostream>
#include <vector>
#include <list>

//A Red Black Tree Problem
//Red means , the node is chosen and black the opposite
//if we choose a node we cant choose its children or better say neighbours
//if we dont choose one we can choose the neighbours as well as turn black as well , whatever is the max
int n;
std::vector<int>ifRed(100000);
std::vector<int>ifBlack(100000);
std::vector<bool>visited(100000);

struct adjacent{
    std::vector<int>verts;
    int size = 0;//This is c++ 11 , remember it during compilling
};

void dfs(int vertex,const std::vector<adjacent> &graph){
    visited[vertex] = true;
    int size = graph[vertex].size;
    for(int i=0;i<size;i++){
        if(!visited[graph[vertex].verts[i]]){
            dfs(graph[vertex].verts[i],graph);
            ifRed[vertex] += ifBlack[graph[vertex].verts[i]]; //If choose it , we cant choose the adjacent vertexes
            int temp = ifRed[graph[vertex].verts[i]];
            if(ifBlack[graph[vertex].verts[i]] > temp){
                temp = ifBlack[graph[vertex].verts[i]];
            }
            ifBlack[vertex] += temp;
        }
    }
}

int main(){
    std::cin >> n;
    std::vector<adjacent>graph(n);
    for(int i=0;i<n;i++){
        std::cin >> ifRed[i];
    }
    
    for(int i=0;i<n-1;i++){
        int a ,b;
        std::cin >> a >> b;
        a--;b--;
        graph[a].verts.push_back(b);
        graph[a].size++;
        graph[b].verts.push_back(a);
        graph[b].size++;
    }
    dfs(0,graph);
    int sum = ifRed[0];
    if(ifBlack[0] > sum){
        sum = ifBlack[0];
    }
    std::cout << sum << std::endl;
    return 0;
}
