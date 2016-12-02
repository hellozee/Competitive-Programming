#include <iostream>
#include <vector>

int main(){
    int machines , tokens , start , end;
    std::cin >> machines >> tokens >> start >> end;
    start--;//end--;
    std::vector<std::vector<int> >tokenTable(machines,std::vector<int>(tokens));
    std::vector<std::vector<int> >machTable(machines,std::vector<int>(tokens));
    std::vector<std::vector<bool> >visited(machines,std::vector<bool>(tokens,false));
    std::vector<int>visitedMach;
    for(int i=0;i<machines;i++){
        for(int j=0;j<tokens;j++){
            int tok , mach;
            std::cin >> tok >> mach;
            tok--;mach--;
            tokenTable[i][j] = tok;
            machTable[i][j] = mach;
        }
    }

    int moves =0 ,token = 0;

    while(moves < end){
        if(visited[start][token]){
            int modFac = end%(moves+1);
            //modFac = modFac + visited[start][token];
            std::cout << visited[start][token] << ' ' << moves <<' ' <<modFac<<std::endl;
            std::cout <<visitedMach[modFac]+1<< ' ' << visitedMach[modFac-1] << ' ' << visitedMach[modFac+1] << std::endl;
            return 0;
        }
        visited[start][token] = true;
        visitedMach.push_back(start);
        int newTok = tokenTable[start][token];
        int newStart = machTable[start][token];
        token = newTok;
        start = newStart;
        moves++;
    }
    std::cout << start+1 << std::endl;
    return 0;
}
