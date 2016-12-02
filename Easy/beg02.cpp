//Troll Question...Never Works

#include <iostream>
#include <iomanip>

int main(){
	int n;
	float f;
	std::cin >> n >> f;

	if(n%5==0 && n < f){
		f = f - n - 0.50;
	}

	std::cout << std::fixed;

	std::cout << std::setprecision(2) << f << std::endl;

	return 0;
}