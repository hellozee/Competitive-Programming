#include <iostream>
#include <vector>
#include <algorithm>

struct event{
    int start;
    int end;
};

bool compare(const event &e1,const event &e2){
    return e1.start < e2.start;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<event>requests(n);
    for(int i=0;i<n;i++){
        int days;
        std::cin >> requests[i].start >> days;
        requests[i].end = requests[i].start + days;
    }
    sort(requests.begin(),requests.end(),compare);
    int possible = 1;
    
    int end = requests[0].end;
    
    for(int i=1;i<n;i++){
        if(end >= requests[i].start){
            end = std::min(end,requests[i].end);
        }else{
            possible++;
            end = requests[i].end;
        }
    }
    
    std::cout << possible << std::endl;
    return 0;
}
