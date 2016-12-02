#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n;
	std::cin >> n;
	std::vector<long long> v(n);
	for (int i =0;i<n;i++){
		std::cin >> v[i];
	}
	sort(v.begin(),v.end());
	long long total = 0;
	for(int i =0;i<n;i++){
		long long price = v[i];
		long long temp = price * (n-i);
		if (total < temp){
			total = temp;
		}
	}
	std::cout<< total << std::endl;
	return 0;
}
