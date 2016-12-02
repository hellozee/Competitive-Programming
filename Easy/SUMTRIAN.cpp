#include <iostream>


int main(){
	int testCases;
	std::cin >> testCases;
	int results[testCases];
	for(int k=0;k<testCases;k++){
		int lines;
		std::cin >> lines;
		int triangle[100][100] = {0};
		for(int i=0;i<lines;i++){
			for(int j=0;j<=i;j++){
				std::cin >> triangle[i][j];
			}
		}
		for(int i = lines-2;i>=0;i--){
			for(int j = 0;j<=lines-2;j++){
				if(triangle[i+1][j] > triangle[i+1][j+1]){
					triangle[i][j] += triangle[i+1][j];
				}else{
					triangle[i][j] += triangle[i+1][j+1];
				}
			}
		}
		results[k] = triangle[0][0];
	}

	for(int l=0;l<testCases;l++){
		std::cout << results[l] << std::endl;
	}
	return 0;
}