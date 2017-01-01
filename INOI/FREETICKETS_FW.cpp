//This one is the same problem but solved with Floyd Warshall Algorithm
#include <iostream>
#include <vector>
#include <climits>

int main(){
    int city,connections;
    std::cin >> city >> connections;
    std::vector<std::vector<int> >graph(city,std::vector<int>(city,INT_MAX));//Adjacency matrix for storing the graph
    for(int i=0;i<connections;i++){
        int a , b;
        std::cin >> a >> b;
        a--;b--;
        std::cin >> graph[a][b];
        graph[b][a] = graph[a][b];
    }
    for (int i=0;i<city;i++)
        graph[i][i] = 0;
    for (int k=0;k<city;k++) {
        for (int i=0;i<city;i++) {
            for (int j=0;j<city;j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    int max = 0;
    for (int i=0;i<city;i++) {
        for (int j=0;j<city;j++) {
            if (graph[i][j] > max)
                max = graph[i][j];
        }
    }
    std::cout << max << std::endl;
    return 0;
}
