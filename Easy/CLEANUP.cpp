#include <iostream>

int main(){
	int testCases;
	std::cin >> testCases;
	while(testCases--){
		int jobs,n;
		std::cin>>jobs>>n;
		if(jobs>0){
		bool todoJobs[jobs] = {false};
		for(int i=0;i<n;i++){
			int testJob;
			std::cin >> testJob;
			todoJobs[testJob-1] = true;
			}
		bool toSkip = false;
		for(int i=0;i<jobs;i++){
			if(todoJobs[i] == false){
				if(toSkip == false){
					std::cout << i+1 << ' ';
					toSkip = true;
					todoJobs[i] = true;
				}else{
					toSkip = false;
				}
			}
		}
		std::cout << std::endl;
		for(int i=0;i<jobs;i++){
			if(todoJobs[i] == false){
				std::cout << i+1 << ' ';
			}
		}
		}
		std::cout << std::endl;
	}
	return 0;
}
