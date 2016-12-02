#include <iostream>

int findHCF(int a,int b){
	if(a==b){
		return a;
	}
	else{
		if(a>b){
			return findHCF(a-b,b);
		}else{
			return findHCF(a,b-a);
		}
	}
}

int multiHCF(int arr[],int size){
	int hcf = findHCF(arr[0],arr[1]);
	for(int i=2;i<size;i++){
		int temp = findHCF(arr[i],hcf);
		if(temp > hcf){
			hcf = temp;
		}
	}
	return hcf;
}

int main(){
	int testCases;
	std::cin>>testCases;
	while(testCases--){
		int n;
		std::cin>>n;
		if(n==1){
			int a;
			std::cin>>a;
			std::cout << a << std::endl;
		}else{
			int numArr[n];
			for(int i=0;i<n;i++){
				std::cin >> numArr[i];
			}
			int hcf = multiHCF(numArr,n);
			for(int i=0;i<n;i++){
				numArr[i] = numArr[i]/hcf;
				std::cout << numArr[i] << ' ' ;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}