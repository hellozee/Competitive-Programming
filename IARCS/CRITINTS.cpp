#include <iostream>
#include <vector>

std::vector<std::vector<int> >adjMat(300,std::vector<int>(300,0));
std::vector<int>parent;
std::vector<bool>visited;
std::vector<int>discT;
std::vector<int>lowT;
std::vector<bool>artPts;

int n;

void dfs(int vertex){
    int children = 0;
    visited[vertex] = true;

    static int time = 0;

    discT[vertex] = lowT[vertex] = ++time;

    for(int i=0;i<n;i++){
        if(adjMat[vertex][i]){
            if(!visited[i]){
                children++;
                parent[i] = vertex;
                dfs(i);
                lowT[vertex] = std::min(lowT[vertex],lowT[i]);

                if(!parent[vertex] && children > 1){
                    artPts[vertex] = true;
                }

                if(parent[vertex] && lowT[i] >= discT[vertex]){
                    artPts[vertex] = true;
                }
            }else if(adjMat[vertex][i] != parent[vertex]){
                lowT[vertex] = std::min(lowT[vertex],discT[i]);
            }
        }
    }
}

int main (int argc, char const* argv[])
{
    int m;

    std::cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        std::cin >> a >> b;
        a--;b--;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    for(int i=0;i<n;i++){
        if(artPts[i] == true){
            std::cout << i+1 << std::endl;
        }
    }

    return 0;
}
