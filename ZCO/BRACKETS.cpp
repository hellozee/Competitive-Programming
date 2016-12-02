#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int depth = 0, depthPos = 0;
    int maxLen = 0, maxPos = 0;
    int temp;
    int counter = 0, curMaxLen = 0, curMaxPos;
    for (int i = 0; i < n; i++){
        std::cin >> temp;
        if (temp == 1){
            counter++;
            if (depth < counter){
                depth = counter;
                depthPos = i;
            }
            if (counter > 1){
                curMaxLen++;
            }else{
                curMaxLen = 0;
                curMaxPos = i;
            }
        }else{
            counter--;
            if (counter > 0){
                curMaxLen++;
            }else{
                if (maxLen < curMaxLen){
                    maxLen = curMaxLen;
                    maxPos = curMaxPos;
                }
                curMaxLen = 0;
                curMaxPos = 0;
            }
        }
    }
    std::cout << depth << " " << depthPos + 1 << " ";
    std::cout << maxLen + 2 << " " << maxPos + 1 << std::endl;
    return 0;
}
