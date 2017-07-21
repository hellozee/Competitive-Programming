#include <iostream>
#include <vector>
#include <queue>

int size = 0;

void remove(std::vector<std::vector<bool> >nobles,std::vector<int>haters,int vertex,int n){
    //std::cout << vertex << std::endl;
    for(int i=1;i<=n;i++){
        if(nobles[i][vertex]){
            nobles[i][vertex] = false;
            haters[i]--;
        }
    }
}

bool possible(std::vector<int>haters,int n,int k,std::vector<std::vector<bool> >nobles,std::vector<bool>selected){
    int count = 0;
    for(int i=1;i<=n;i++){
        if(haters[i] < k && selected[i]){
            remove(nobles,haters,i,n);
            selected[i] = false;
            std::cout << i << std::endl;
            size--;
            count++;
            //std::cout << size << ' ' << i << std::endl;
        }
    }
    if(count == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,m,k;
    std::cin >> n >> m >> k;
    size = n;
    std::vector<int>haters(n+1,0);
    std::vector<std::vector<bool> >nobles(n+1,std::vector<bool>(n+1,false));
    for(int i=0;i<m;i++){
        int a , b;
        std::cin >> a >> b;
        nobles[a][b] = true;
        nobles[b][a] = true;
        haters[a]++;
        haters[b]++;
    }
    std::vector<bool>selected(n+1,true);
    bool temp = possible(haters,n,k,nobles,selected);
    while(!temp){
        temp = possible(haters,n,k,nobles,selected);
        if(size == 0){
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    std::cout << size << std::endl;
    return 0;
}
