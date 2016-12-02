#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main(){
	int n;
	std::cin >> n;
	std::vector<int>results;
	for(int i=0;i<n;i++){
		int t;
		std::cin >> t;
		int cases = 0;
		for(int i=5;t/i >= 1;i = i*5){
			cases = cases + t/i;
		}
		results.push_back(cases);
	}

	for(int c : results){
		std::cout << c << std::endl;
	}
	return 0;
}