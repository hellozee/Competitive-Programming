#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>perm(n+1);
    std::vector<bool>visited(n+1,false);
    std::vector<std::vector<int> >cycles;
    for(int i=1;i<n+1;i++){
        std::cin >> perm[i];
    }
    int count = 0;
    for(int i=1;i<n+1;i++){
        if(!visited[perm[i]]){
            int start = perm[i];
            int sec = perm[start];
            cycles.resize(count+1);
            cycles[count].push_back(start);
            if(start == sec){
                cycles[count].push_back(sec);
            }
            visited[start] = true;
            visited[sec] = true;
            while(sec != start){
                cycles[count].push_back(sec);
                sec = perm[sec];
                visited[sec] = true;
            }
            count++;
        }
    }
    std::cout << count << std::endl;
    
    for(int i=0;i<count;i++){
        int size = cycles[i].size();
        if(cycles[i][0] != cycles[i][1]){
            std::cout << cycles[i][size-1] << ' ';
        }
        for(int j=0;j<size;j++){
            std::cout << cycles[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
