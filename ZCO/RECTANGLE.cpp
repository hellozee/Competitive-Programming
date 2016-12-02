#include <iostream>
#include <vector>
#include <algorithm>

typedef struct point{
    int x;
    int y;
}point;

bool sortX(point a,point b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool sortY(point a,point b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<point>xSorted(n+4);
    for(int i=0;i<n;i++){
        std::cin>> xSorted[i].x >> xSorted[i].y;
    }

    xSorted[n].x   =      0; xSorted[n].y   =   0;
    xSorted[n+1].x =      0; xSorted[n+1].y = 500;
    xSorted[n+2].x = 100000; xSorted[n+2].y =   0;
    xSorted[n+3].x = 100000; xSorted[n+3].y = 500;

    std::vector<point>ySorted(xSorted);

    sort(xSorted.begin(),xSorted.end(),sortX);
    sort(ySorted.begin(),ySorted.end(),sortY);

    long long maxarea = 0;

    for(int i=1;i<n+4;i++){
        long long area = (xSorted[i].x-xSorted[i-1].x) * 500;
        if(area > maxarea){
            maxarea = area;
        }
    }

    std::cout << maxarea << std::endl;
    return 0;
}
