#include <iostream>
#include <vector>
#include <string>

int main(){
    int tweets , clicks;
    std::cin >> tweets >> clicks;
    int openTweets = 0;
    std::vector<bool>whetherOpen(tweets,false);
    while(clicks--){
        //int num = 1;
        std::string input;
        std::cin >> input;
        if(input == "CLICK"){
            int num;
            std::cin >> num;
            if(whetherOpen[num-1]){
                whetherOpen[num-1] = false;
                openTweets--;
            }else{
                whetherOpen[num-1] = true;
                openTweets++;
            }
        }else{
            whetherOpen = std::vector<bool>(tweets,false);
            openTweets = 0;
        }
        std::cout << openTweets << std::endl;
        //std::cout << whetherOpen[0] << whetherOpen[1] << whetherOpen[2] << std::endl;
    }
    return 0;
}
