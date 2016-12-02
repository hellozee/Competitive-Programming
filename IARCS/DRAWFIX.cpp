#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool ordering(const std::pair<int,int>first,const std::pair<int,int>second){
    return first.second > second.second;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int> >home(n);
    std::vector<std::pair<int,int> >visitors(n);// Pair for maintaining the index when they are sorted
    for(int i=0;i<n;i++){
        std::cin >> home[i].second;
        home[i].first = i;// first one in the index , next comes the ELO rating for the player
    }
    for(int i=0;i<n;i++){
        std::cin >> visitors[i].second;
        visitors[i].first = i;
    }
    
    sort(home.begin(),home.end(),ordering);
    sort(visitors.begin(),visitors.end(),ordering);// both the teams are sorted
    
    /*for(int i=0;i<n;i++){
        std::cout << home[i].first+1 << ' ' << visitors[i].first+1 << std::endl;
    }*/
    std::vector<int>greater(n,-1);
    std::vector<int>remaining;
    int sizeG = 0;
    int sizeR = 0;
   /* int size = 0;
    int i=0,j=0,k=n-1;  //Another process copied from a solution ,  simillar to mine one but still it doesnt works
    while(j<n){
        if(home[i].second < visitors[j].second){   
            greater[home[k].first] = visitors[j].first;
            j++;k--;
        }else{
            greater[home[i].first] = visitors[j].first;
            i++;j++;size++;
        }
    }
    std::cout << size << std::endl;
    for(int i=0;i<n;i++){
        std::cout << greater[i]+1<< std::endl;
    }*/
    for(int i=0;i<n;i++){
        if(visitors[i].second < home[sizeG].second){
            //std::cout << visitors[i].second << ' ' << home[sizeG].second << ' ' << home[sizeG].first << std::endl;
            greater[home[sizeG].first] = visitors[i].first+1;
            //std::cout<< home[sizeG].first+1 << ' ' <<visitors[i].first+1 << std::endl;
            sizeG++;
        }else{
            remaining.push_back(visitors[i].first+1);
            sizeR++;
        }
    }
    std::cout << sizeG << std::endl;
    //std::cout << std::endl;
    int j=sizeR-1;
    for(int i=0;i<n;i++){
        if(greater[i] == -1){
            greater[i] = remaining[j];
            j--;
        }
        std::cout << greater[i] << std::endl;
    }
    /*std::cout << std::endl;
    for(int i=0;i<sizeR;i++){
        std::cout << remaining[i] << std::endl;
    }*/
    return 0;
}
