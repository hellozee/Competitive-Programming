#include <iostream>
#include <vector>
#include <algorithm>

struct kingdom{
    int start;
    int end;
};

bool comp(const kingdom &a , const kingdom &b){
    return a.start < b.start;
}

int main(){
    int testCases;
    std::cin >> testCases;
    while(testCases--){
        int n;
        std::cin >> n;
        std::vector<kingdom>intervals(n);
        for(int i=0;i<n;i++){
            std::cin >> intervals[i].start >> intervals[i].end;
        }
        sort(intervals.begin(),intervals.end(),comp);
        int count = 1;
        int end = intervals[0].end;
        for(int i=1;i<n;i++){
            if(end < intervals[i].start){
                count++;
                end = intervals[i].end;
            }else{
                end = std::min(end,intervals[i].end);
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
