#include <iostream>
#include <vector>
#include <algorithm>

typedef struct timetaken{
    int cobol;
    int rest;
}timetaken;

bool compare(timetaken a, timetaken b){
    return a.rest > b.rest;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<timetaken>citizens(n);
    for(int i=0;i<n;i++){
        timetaken a;
        std::cin >> a.cobol;
        int b,c;
        std::cin >> b >> c;
        a.rest = b+c;
        citizens[i] = a;
    }
    sort(citizens.begin(),citizens.end(),compare);
    int mintime = 0;
    int prevtime = 0;
    for(int i=0;i<n;i++){
        int time = prevtime + citizens[i].cobol + citizens[i].rest;
        //std::cout << time << ' ' << prevtime << std::endl;
        if(time > mintime){
            mintime = time;
        } 
        prevtime = prevtime + citizens[i].cobol;
        //std::cout << prevtime << std::endl;
    }
    std::cout << mintime << std::endl;
    return 0;
}
