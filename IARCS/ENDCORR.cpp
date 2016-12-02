#include <iostream>
#include <queue>

int main (){
    int N = 0, M = 0, input = 0;
    std::priority_queue<int> sortedWealthList;
    std::cin >> N >> M;
    for(int inputLine = 0; inputLine < N + M; ++inputLine){
        std::cin >> input;
        if (input == -1){
            std::cout << sortedWealthList.top() << std::endl;
            sortedWealthList.pop();
        }
        else{
            sortedWealthList.push(input);
        }
    }
    return 0;
}
