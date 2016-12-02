#include <iostream>

int main(){
	std::string ret="";
	while(true){
		int n;
		std::cin>>n;
		if(n==0){
			break;
		}
		int permut[n];
		for(int i=0;i<n;i++){
			std::cin>>permut[i];
		}
		int inverse[n];
		for(int i=0;i<n;i++){
			int c= permut[i];
			inverse[c-1] = i+1;
		}
		bool check;
		for(int i=0;i<n;i++){
			if(permut[i]==inverse[i]){
				check = true;
			}else{
				check = false;
				break;
			}
		}
		if(check == true){
			std::cout << "ambiguous" << std::endl;
		}else{
			std::cout << "not ambiguous" << std::endl;
		}
	}
	return 0;
}