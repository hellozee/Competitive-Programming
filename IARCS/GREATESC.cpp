#include <iostream>
#include <vector>
#include <queue>

int main (int argc, char const* argv[])
{
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> >table(n,std::vector<int>(n));
    while(m--){
        int a ,b;
        std::cin >> a >> b;
        table[a-1][b-1] = 1;
        table[b-1][a-1] = 1;
    }
    int start , end;
    std::cin >> start >> end;
    start--;end--;
    std::vector<bool>visited(n);
    std::queue<int>queue_;
    visited[start] = true;
    queue_.push(start);
    std::vector<int>minDist(n);
    std::fill(minDist.begin(),minDist.end(),31000);
    minDist[start] = 0;
    while(!queue_.empty()){
        int s = queue_.front();
        queue_.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && table[s][i] == 1){
                visited[i] = true;
                minDist[i] = std::min(minDist[i],minDist[s]+1);
                queue_.push(i);
            }
        }
    }
    if(minDist[end] == 31000){
        std::cout << 0 << std::endl;
    }else{
        std::cout << minDist[end] << std::endl;
    }
    return 0;
}
