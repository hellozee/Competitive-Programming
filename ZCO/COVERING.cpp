#include <iostream>
#include <vector>
#include <algorithm>

//for keeping the records , simpler and readable then the normal std::pair
struct pair{
    int start;
    int end;
};

//Comparison function for sorting the points by their starting number
bool comp(const pair &p1,const pair &p2){
    return p1.start < p2.start;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<pair>intervals(n);
    for(int i=0;i<n;i++){
        std::cin >> intervals[i].start >> intervals[i].end;
    }
    sort(intervals.begin(),intervals.end(),comp);
    int end = intervals[0].end;//setting up the end as the end of the first interval
    int count = 1;//the minimum number of possiblle sets
    for(int i=1;i<n;i++){
        if(end < intervals[i].start){//current interval is a disjoint set hence we need at least another element for covering it
            count++;
            end = intervals[i].end;
        }else{
            end = std::min(intervals[i].end,end); // current interval has its end inside the previous interval
        }                                         // so we dont need any extra element for covering it 
    }
    std::cout << count << std::endl;
    return 0;
}

