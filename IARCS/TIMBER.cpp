#include <iostream>
#include <vector>
#include <sstream>

int main(){
    int n,m;
    std::ios_base::sync_with_stdio(false);
    std::stringstream ss;
    std::cin >> n >> m;
    std::vector<std::vector<int> >matrix(n,std::vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin >> matrix[i][j];
            //std::cout << i << ' ' << j << std::endl;
        }
    }
    std::vector<std::vector<int> >sums(n,std::vector<int>(m));
    sums[n-1][m-1] = matrix[n-1][m-1];
    //std::cout << "got here" << std::endl;
    for(int i=m-2;i>=0;i--){
        sums[n-1][i] = matrix[n-1][i] + sums[n-1][i+1]; 
    }
    //std::cout << "got here" << std::endl;
    for(int i=n-2;i>=0;i--){
        sums[i][m-1] = matrix[i][m-1] + sums[i+1][m-1]; 
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            sums[i][j] = sums[i+1][j] + sums[i][j+1] - sums[i+1][j+1] + matrix[i][j];
        }
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout << sums[i][j] << ' ';
        }
        std::cout << std::endl;
    }*/
    int c;
    std::cin >> c;
    int x1,y1,x2,y2;
    for(int i=0;i<c;i++){
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        if(x2 == n-1 && y2 == n-1){
            ss << sums[x1][y1] << std::endl;
        }else if(x2 == n-1 && y2 != n-1){
            ss << sums[x1][y1] - sums[x1][y2+1] << std::endl;
        }else if(x2 != n-1 && y2 == n-1){
            ss << sums[x1][y1] - sums[x2+1][y1] << std::endl;
        }else{
            ss << sums[x1][y1] + sums[x2+1][y2+1] - sums[x1][y2+1] - sums[x2+1][y1] << std::endl;
        }
    }
    std::cout << ss.str();
}
