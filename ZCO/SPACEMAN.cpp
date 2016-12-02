#include <iostream>
#include <vector>

struct blaster{
    int x;
    int y;
    int start;
    int freq;
};

int main(){

    int n , m ,k;
    std::cin >> n >> m >>k;
    std::vector<std::vector<int> >grid(n,std::vector<int>(m,0));
    std::vector<blaster>guns(k);
    for(int i=0;i<k;i++){
        std::cin >> guns[i].x >> guns[i].y >> guns[i].start >> guns[i].freq;
        guns[i].x--;guns[i].y--;
    }

    std::vector<bool>starts(k,false);
    
    return 0;
}
