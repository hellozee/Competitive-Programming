//Author  : Kuntal Majumder
//Problem : 01TILES

#include <iostream>

int main(){

	int n;
	std::cin >> n;
	int f1 = 1;
	int f2 = 1;
	int fn;

	for( int i = 0;i < n-1;i ++){
		fn = (f1+f2)%15746;
		f1 = f2;
		f2 = fn;
	}

	std::cout << f2 << std::endl;


	return 0;
}
/*
Preparing algorithm for 8 :

_ _ _ _ _ _ _ _
n - n + 1 = 1

0 0 _ _ _ _ _ _
n-2 + 1 = 7

0 0 0 0 _ _ _ _ n- 4 +1 = 5
_ 0 0 0 0 _ _ _ n - 5 +1 = 4
_ _ 0 0 0 0 _ _ n - 6 +1 = 3
_ _ _ 0 0 0 0 _ n - 7 + 1 = 2
_ _ _ _ 0 0 0 0 n - 8 + 1 = 1
                            15
0 0 0 0 0 0 _ _ n - 6 + 1 = 3
0 0 _ 0 0 0 0 _ n - 7 + 1 = 2
0 0 _ _ 0 0 0 0 n - 8 + 1 = 1
_ 0 0 0 0 0 0 _ n - 7 + 1 = 2
_ 0 0 _ 0 0 0 0 n - 8 +1 = 1
_ _ 0 0 0 0 0 0 n - 8 + 1 = 1
                           10
0 0 0 0 0 0 0 0 n - 8 +1 = 1
                          34
*/
