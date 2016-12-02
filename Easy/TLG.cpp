#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main(){
	long int t,p=1,max=0,a=0,b=0;
	cin>>t;
	while(t--){
		int c,d;
		cin>>c>>d;
		a+=c;
		b+=d;
		if(max<a-b){
			p=1;
			max=a-b;
		}else if(max<b-a){
			p=2;
			max=b-a;
		}
	}
	cout<<p<<" "<<max;
	return 0;
}   
