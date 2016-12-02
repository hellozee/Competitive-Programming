#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>loadTestCases(int n){
	std::vector<int>elems;
	for(int i =0;i<n;i++){
		int cases;
		std::cin >> cases;
		elems.push_back(cases);
	}
	return elems;
}

int main(){
	int numberofStacks,maxHeight;
	std::cin >> numberofStacks >> maxHeight;
	std::vector<int> stack = loadTestCases(numberofStacks);
	std::vector<int> cmds;
	while(true){
		int temp;
		std::cin >> temp;
		if(temp == 0){
			break;
		}
		cmds.push_back(temp);

	}


	int curPos = 0;
	bool isHolding = false;

	for (int i : cmds){
		if(i==0){
			break;
		}
		if(i==1){
			if(curPos > 0){
				curPos = curPos -1;

			}
		}
		if(i==2){
			if(curPos < numberofStacks-1){
				curPos = curPos + 1;
			}
		}
		if(i==3){
			if(isHolding == false && stack.at(curPos) > 0){
				stack.at(curPos) = stack.at(curPos) - 1;
				isHolding = true;
			}
		}
		if(i==4){
			if (isHolding == true && stack.at(curPos) < maxHeight){
				stack.at(curPos) = stack.at(curPos) + 1;
				isHolding = false;
			}
		}
	}
	for (int it: stack){
		std::cout << it << ' ';
	}

	std::cout << std::endl;
	return 0;
}