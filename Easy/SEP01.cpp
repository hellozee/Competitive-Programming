#include <iostream>
#include <string>



int main(){
	int n;
	std::cin>>n;
	std::string retStr = "";
	for(int i=0;i<n;i++){
		std::string cases;
		std::cin>>cases;
		int c=0,d=0;
		for(int j=0;j<cases.length();j++){
			if(cases[j] == '1'){
				c++;
			}
			if(cases[j] == '0'){
				d++;
			}
		}
		if(c==1 || d==1){
			retStr = retStr + "Yes\n";
		}else{
			retStr = retStr + "No\n";
		}

	}
	std::cout << retStr;
	return 0;
}