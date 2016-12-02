#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    std::vector<int> j;
    for(int i=0;i<t;i++){
    	int n;
    	std::cin >> n;
    	int m = (n/2)+1;
    	j.push_back(m);
    	}
    for(int m: j){
    	std::cout << m << std::endl;
    }
    return 0;
}