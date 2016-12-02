#include <iostream>
#include <vector>

std::vector<int>genSegtree(int size){
    
}

void update(std::vector<int>segtree,int start,int end){
    
}

int count(std::vector<int>segtree,int start,int end){
    
}

int main(){
    int n,q;
    std::cin >> n >> q;
    std::vector<int>coins = genSegtree(n);
    while(q--){
        int command , start, end;
        std::cin >> command >> start >> end;
        if(command){
            std::cout << count(coins,start,end) << std::endl;
        }else{
            update(coins,start,end);
        }
    }
    return 0;
}
