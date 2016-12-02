#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int mems[n];
	int res[n]={0};
	for(int i=0;i<n;i++){
		std::cin >> mems[i];
	}

	for(int i=0;i<n;i++){
		res[mems[i]-1] = res[mems[i]] + 1  ;
	}

	for(int i=0;i<n;i++){
		if(res[i]==0){
			std::cout << i+1 << ' ';
		}
	}
	std::cout << std::endl;

	return 0;
}