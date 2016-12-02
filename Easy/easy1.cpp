#include <iostream>
#include <vector>
#include <string>

std::vector<int>loadTestCases(int N){
	std::vector<int> testCases;
	for(int i =0;i < N;i++){
		int cases;
		std::cin >> cases;
		testCases.push_back(cases);
	}
	return testCases;
}

int main(){
	bool test = false;
	std::string retStr = "";
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::vector<int>args = loadTestCases(2);
		int m = args.at(1);
		std::vector<int>data = loadTestCases(m);
		for(int j=1;j<=args.at(0);j++){
			for(int k = 0; k<m;k++){
				if(j != data.at(k)){
					test = true;
					break;
				}
				else{
					test = false;
				}
			}
			
		}
	}
	std::cout << retStr << std::endl;
	return 0;
}

/*int main(){

	std::vector<int>tcases = loadTestCases(2);
	int i = tcases.at(0) - tcases.at(1);
	if(i%10 == 9){
		i--;
	}else{
		i++;
	}
	std::cout << i << std::endl;
	return 0;
}*/
