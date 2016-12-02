#include <iostream>

int main(){
	int a =0, n ,k;
	std::cin >> n >> k;

	for (int i=0;i<n;i++){
		int c;
		std::cin >> c;
		if(c%k == 0){
			a++;
		}
	}

	std::cout << a << std::endl;

	return 0;
}