#include <iostream>

int main(){

	int n;
	std::cin >> n;
	int pre = 1;
	int cur = 1;
	int fib;

	for( int i = 0;i < n-1;i ++){
		fib = (pre+cur)%15746;
		pre = cur;
		cur = fib;
	}

	std::cout << cur;


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
