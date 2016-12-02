#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<int>loadTestCases(int N){
    std::vector<int> testCases;
    for (int i = 0; i < N; i++)
    {
        int TestCase;
        std::cin >> TestCase;
        testCases.push_back(TestCase);
    }
    return testCases;
}

int main(){

	int args,k;
	std::cin >> args >> k;

	std::vector<int> nums = loadTestCases(args);
	int cases = 0;

	sort(nums.begin(),nums.end());


	for(int i=1;i<args;i++){
		int temp = std::abs(nums.at(i)-nums.at(i-1));
		if(temp >=k){
			cases = cases + i;
		}else{
			int j = i;
			while(temp < k && j > 0){
				j--;
				temp = std::abs(nums.at(i)-nums.at(j));
			}
			if(temp >= k){
				cases = cases + j + 1;
			}
		}
	}

	std::cout << cases << std::endl;
	return 0;
}