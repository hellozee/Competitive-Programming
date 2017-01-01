//Stop overhyping this problem , this wont need a 4D matrix , it would probably take much more space than expect and would
//be more complicated , this is a solution using 2 2D matrix , a simple one though

#include <iostream>
#include <vector>

#define MOD 20011

int main(){
    int n,m,d;
    std::cin >> n >> m >> d;
    std::vector<std::vector<int> >fromTop(n,std::vector<int>(m,0));
    std::vector<std::vector<int> >fromLeft(n,std::vector<int>(m,0));
    std::vector<std::vector<int> >ifPossible(n,std::vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin >> ifPossible[i][j];
        }
    }
    
    fromTop[0][0] = 1;
    fromLeft[0][0] = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 && j==0) || !ifPossible[i][j]){
                continue;
            }
            int ways = 0;
            //Algorithm:
            //fromLeft[i][j] = fromTop[i-1][j] + fromTop[i-2][j] +....+ fromTop[i-d][j]
            //fromTop [i][j] = fromLeft[i][j-1] + fromLeft[i][j-2] +....+ fromLeft[i][j-d]
            int min = i-d;
            if(min < 0){
                min = 0;
            }
            for(int k=i-1; k>=min;k--){
                if(!ifPossible[k][j]){
                    break;
                }
                ways += fromTop[k][j];
            }
            fromLeft[i][j] = ways%MOD;
            ways = 0;
            min = j-d;
            if(min < 0){
                min = 0;
            }
            for(int k=j-1;k>=min;k--){
                if(!ifPossible[i][k]){
                    break;
                }
                ways += fromLeft[i][k];
            }
            fromTop[i][j] = ways%MOD;
        }
    }
    std::cout << (fromLeft[n-1][m-1] + fromTop[n-1][m-1])%MOD << std::endl;
    return 0;
}
