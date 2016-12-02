#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>loadTestCases(int n){
	std::vector<int>elems;
	elems.reserve(n);
	for(int i=0;i<n;i++){
		int cases;
		std::cin >> cases;
		elems.push_back(cases);
	}
	return elems;
}

int main(){
	int n ,k;
	std::cin >> n >> k;
	std::vector<int>args = loadTestCases(n);
	long long count = 0;
	sort(args.begin(),args.end());
	int l = args.size();
	for(int i=0,j=l -1;i<j;i++){
		while(j > i && args.at(i)+args.at(j) >= k){
			j--;
		}
		count = count + j - i;
	}
	std::cout << count <<std::endl;
}