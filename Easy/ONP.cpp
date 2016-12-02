#include <iostream>
#include <string>
#include <cstdlib>


int main(){
	int testCases;
	std::cin >> testCases;
	while(testCases--){
		std::string input,result,symbol;
		std::cin>> input;
		int len = input.size();
		int j=-1;
		for(int i=0;i<len;i++){
			if(input[i] == '('){
				continue;
			}else if(isalpha(input[i])){
				result= result + input[i];
			}else if(input[i]==')'){
				result = result + symbol[j];
				j--;
			}else{
				j++;
				symbol[j] = input[i];
			}
		}
		std::cout << result << std::endl;
	}
}