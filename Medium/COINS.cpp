#include <iostream>
#include <map>

std::map<int,long long>map;

long long breakup(int coin /*, std::map<int ,long long> &map*/){
    if(coin == 0){
        return 0;
    }
    if(map[coin] != 0){
        return map[coin];
    }
    long long temp = breakup(coin/2/*,map*/) + breakup(coin/3/*,map*/) + breakup(coin/4/*,map*/);
    if(temp > coin){
        map[coin] = temp;
    }else{
        map[coin] = coin;
    }
    return map[coin];
}

int main(){
    long long n;
    //std::cin >> n;
    while(std::cin >> n && !std::cin.eof()){
        map.clear();
        std::cout << breakup(n) << std::endl;
    }
    //static std::map<int,long long>map;
    //std::cout << breakup(n/*,map*/) << std::endl;
    return 0;
}

