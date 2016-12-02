#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<bool>bamboo(100000);
    int max = 0;
    for(int i=0;i<n;i++){
        int a;
        std::cin >>a;
        bamboo[a] = true;
        if(a > max){
            max = a;
        }
    }
    int maxcount = 1;
    for(int i=0;i<=max;i++){
        if(bamboo[i]){
            for(int j=i+1;j<=max;j++){
                if(bamboo[j]){
                    int count = 1;
                    int pos = j;
                    int difference = j-i;
                    //std::cout << pos << std::endl;
                    while(pos <= max){
                        if(bamboo[pos]){
                            pos = pos + difference;
                            count++;
                            //std::cout << pos << ' ';
                        }else{
                            break;
                        }
                    }
                    if(count > maxcount){
                        maxcount = count;
                    }
                    //std::cout << std::endl;
                }
            }
        }
    }
    std::cout << maxcount << std::endl;
    return 0;
}
