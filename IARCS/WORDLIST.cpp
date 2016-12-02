#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>



int main(){
	int n; 
	std::vector<std::string> elements;
	std::string total = "";
	std::cin >> n;
	std::cin.ignore();
	for(int i=0;i<n;i++){
		std::string testCase;
		getline(std::cin,testCase);
		total = total + testCase + " ";
	}
	total.erase(std::remove_if(total.begin(),total.end(),ispunct), total.end());
	std::transform(total.begin(),total.end(),total.begin(),::tolower);
    std::stringstream ss(total);
    std::string item;
    while(getline(ss,item,' ')){
        elements.push_back(item);
    }
    std::string prev = "";
    sort(elements.begin(),elements.end());
    std::vector<std::string>sorted;
    for(int i=0;i<elements.size();i++){
        if(elements[i] != prev){
            sorted.push_back(elements[i]);
        }
        prev = elements[i];
    }
    std::cout << sorted.size() << std::endl;
    for(int i=0;i<sorted.size();i++){
        std::cout << sorted[i] << std::endl;
    }

	return 0;
}
