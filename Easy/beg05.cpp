#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>split(int n){
	std::vector<int>elems;
	while(n%10){
		elems.push_back(n%10);
		n = n/10;
	}
	return elems;
}

std::vector<int>nextInt(std::vector<int> d,int i=0){
	if(d.at(i) > 0){
		d.at(i)--;
		return d;
	}else{
		d.at(i) = 9;
		return nextInt(d,i++);
	}
}

std::vector<int>add(std::vector<std::vector<int>> v){
	std::vector<int>elems;
	std::vector<int>size;
	for(std::vector<int>i : v){
		size.push_back(i.size());
	}
	sort(size.rend(),size.rbegin());
	int maxSize = size.at(0);
	for(int i=0;i < maxSize +v.size()-1;i++){
		int k = 0;
		for(std::vector<int>j :v){
			elems.push_back(j[i-k]+elems[i]);
			k++;
		}
	}
	return elems;
}

std::vector<int>multiply(std::vector<int> v1 , std::vector<int> v2){
	std::vector<std::vector<int>>holder;
	for(int i:v1){
		std::vector<int>res;
		for(int j : v2){
			res.push_back(i*j);
		}
		holder.push_back(res);
	}
	return add(holder);
}

std::vector<int>factorial(std::vector<int> d){

	if(d.size()==1 && d.at(0) == 1){
		std::vector<int>one;
		one.push_back(1);
		return one;
	}else{
		return multiply(d , factorial(nextInt(d)));
	}
}

int main(){
	int a;
	std::cin >> a;
	std::vector<std::vector<int>>results;
	while(a--){
		int c;
		std::cin >> c;
		std::vector<int>computed = factorial(split(c));
		results.push_back(computed);
	}
	for(std::vector<int>v:results){
		for(int i =v.size();i>=0;--i){
			std::cout << v.at(i);
		}
		std::cout << std::endl;
	}
	return 0;
}