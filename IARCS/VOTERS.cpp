#include <iostream>
#include <map>
#include <vector>

int main(){
    int n1,n2,n3;
    std::cin >> n1 >> n2 >> n3;
    std::map<int,int>record;
    std::vector<int>voters;
    
    for(int i=0;i<n1;i++){
        int temp;
        std::cin >> temp;
        record[temp]++;
    }
    for(int i=0;i<n2;i++){
        int temp;
        std::cin >> temp;
        record[temp]++;
    }
    for(int i=0;i<n3;i++){
        int temp;
        std::cin >> temp;
        record[temp]++;
    }
    int count = 0;
    for(std::map<int,int>::iterator itr = record.begin(); itr != record.end(); ++itr){
        if(itr->second > 1){
            count++;
            voters.push_back(itr->first);
        }
    }
    std::cout << count << std::endl;
    for(int i=0;i<count;i++){
        std::cout << voters[i] << std::endl;
    }
    return 0;
}
