#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::vector<int> &v1,const std::vector<int> &v2){
    int i=0;
    while(i < 51){
        if(v1[i] < v2[i]){
            return true;
        }else if(v1[i] > v2[i]){
            return false;
        }
        i++;
    }
    return false;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int> >rows(n,std::vector<int>(51,0));
    for(int i=0;i<n;i++){
        int temp,size=0;;
        while(true){
            std::cin >> temp;
            if(temp == -1){
                break;
            }
            rows[i][size] = temp;
            size++;
        }
    }
    sort(rows.begin(),rows.end(),compare);
    for(int i=0;i<n;i++){
        for(int j=0;j<51;j++){
            if(rows[i][j] == 0){
                break;
            }
            std::cout << rows[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
