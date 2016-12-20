#include <iostream>
#include <vector>

int main(){
    int machines , tokens , start , end;
    int total;
    std::cin >> machines >> tokens >> start >> end;
    total = machines * tokens;
    start--;end--;
    std::vector<std::vector<int> >tokenTable(machines,std::vector<int>(tokens));
    std::vector<std::vector<int> >machTable(machines,std::vector<int>(tokens));
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

    int token = 0;

    // If there are a lot of moves, then find a cycle first and then reduce
    // the number of moves to something less than the cycle length.
    if (end > total * 3) {
        // First, make M*T moves.
        for (int moves = 0; moves < total; moves++) {
            int newTok = tokenTable[start][token];
            int newStart = machTable[start][token];
            token = newTok;
            start = newStart;
        }
        // Next, count the number of moves until we reach this spot again.
        int cycleStart = start;
        int cycleToken = token;
        int cycleLength = 0;
        do {
            int newTok = tokenTable[start][token];
            int newStart = machTable[start][token];
            token = newTok;
            start = newStart;
            cycleLength++;
        } while (start != cycleStart || token != cycleToken);
        // Now, we can reduce the number of total moves.
        end = (end - total) % cycleLength;
    }

    // Now make moves until we reach the end.
    for (int moves = 0; moves < end; moves++) {
        int newTok = tokenTable[start][token];
        int newStart = machTable[start][token];
        token = newTok;
        start = newStart;
    }
    std::cout << start+1 << std::endl;
    return 0;
}
