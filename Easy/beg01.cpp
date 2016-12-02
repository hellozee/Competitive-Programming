#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int>s;
	while(true){
		int n;
		std::cin>>n;
		if(n==42){
			break;
		}
		s.push_back(n);
	}
	for(int n:s){
		std::cout << n << std::endl;
	}
}