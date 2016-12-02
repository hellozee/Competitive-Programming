#include <iostream>
#include <string>

int main(){
	std::string retStr = "";
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::string a;
		std::cin >> a;
		int l = a.length();
		if(l%2 == 0){
			for(int j=0;j<l;j++){
				if(a[j] == '.'){
					a[j] = a[l-j];
				}
			}
		}else{
			for(int j=0;j<l;j++){
				if(a[j]=='.' && j==l-1/2){
					break;
				}else{
					if(a[j] == '.'){
					a[j] = a[l-j];
					}
				}
			}
		}
		int k=0;
		while(k<l){
			if(a[k] != a[l-k]){
				break;
			}
		}
		if(k == l-1){
			retStr = a + '\n';
		}else{
			retStr = "-1\n";
		}
	}
	std::cout << retStr ;
}