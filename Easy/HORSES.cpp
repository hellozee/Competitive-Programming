#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int testCases;
	std::cin>> testCases;
	while(testCases--){
		int n;
		std::cin >> n;
		std::vector<int>skills;
		while(n--){
			int cases;
			std::cin >> cases;
			skills.push_back(cases);
		}

		sort(skills.begin(),skills.end());
		std::vector<int>diffs;
		for(int i=1;i<skills.size();i++){
			int diff = skills[i] - skills[i-1];
			diffs.push_back(diff);
		}
		sort(diffs.begin(),diffs.end());
		std::cout << diffs[0] << std::endl;

	}
	return 0;
}