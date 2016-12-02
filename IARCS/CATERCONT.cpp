#include <iostream>
#include <vector>

struct conn{
    int from;
    int to;
};

int main(){
    int n;
    std::cin >> n;
    std::vector<int>weights(n);
    std::vector<conn>nextVert(n);
    for(int i=0;i<n;i++){
        std::cin >> weights[i];
    }
    for(int i=0;i<n;i++){
        std::cin >> nextVert[i].from >> nextVert[i].to;
        nextVert[i].from--;nextVert[i].to--;
    }
    
    
    return 0;
}
