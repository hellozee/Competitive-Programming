#include <iostream>

int main(){
	int menu[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
	int testCases;
	std::cin >> testCases;
	for(int i=0;i<testCases;i++){
		int p=0;
		std::cin>>p;
		int n=0;
		while(p){
			for(int j=11;j>=0;j--){
				if(p >= menu[j]){
					p = p-menu[j];
					n++;
					break;
				}
			}
		}
		std::cout << n <<std::endl;
	}

	return 0;
}