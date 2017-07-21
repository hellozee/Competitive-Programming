#include <iostream>
#include <vector>
#include <queue>

struct combo{
    char t,r,b,l;
};

int findturns(combo c1,combo c2,char pos){
    if(pos == 't'){
        if(c1.t == c2.b){
            return 0;
        }
        if(c1.l == c2.b){
            return 1;
        }
        if(c1.b == c2.b){
            return 2;
        }
        if(c1.r == c2.b){
            return 3;
        }
    }
    if(pos == 'b'){
        if(c1.b == c2.t){
            return 0;
        }
        if(c1.r == c2.t){
            return 1;
        }
        if(c1.t == c2.t){
            return 2;
        }
        if(c1.l == c2.t){
            return 3;
        }
    }
    if(pos == 'r'){
        if(c1.r == c2.l){
            return 0;
        }
        if(c1.t == c2.l){
            return 1;
        }
        if(c1.l == c2.l){
            return 2;
        }
        if(c1.b == c2.l){
            return 3;
        }
    }
    if(pos == 'l'){
        if(c1.l == c2.r){
            return 0;
        }
        if(c1.b == c2.r){
            return 1;
        }
        if(c1.r == c2.r){
            return 2;
        }
        if(c1.t == c2.r){
            return 3;
        }
    }
}

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<combo> >combinations(n,std::vector<combo>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin >> combinations[i][j].t >> combinations[i][j].r >> combinations[i][j].b >> combinations[i][j].l;
        }
    }
}
