#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<bool> >paths(501,std::vector<bool>(501,0));
/*
void addpts(/*std::vector<std::vector<int> >paths,int x,int y,int remaining,int size){
  if(remaining > 0){
    remaining--;
    paths[x][y]++;
    //std::cout << x << ' ' << y << std::endl;
    if(x-1 >= 0 /*&& !paths[x-1][y]){
        paths[x-1][y] += 1;
        addpts(/*paths,x-1,y,remaining,size);
    }
    if(x+1 < size && !paths[x+1][y]){
        paths[x+1][y] += 1;
        addpts(paths,x+1,y,remaining,size);
    }
    if(y-1 >= 0 /*&& !paths[x][y-1]){
        paths[x][y-1] += 1;
        addpts(/*paths,x,y-1,remaining,size);
    }
    if(y+1 < size /*&& !paths[x][y+1]){
        paths[x][y+1] += 1;
        addpts(/*paths,x,y+1,remaining,size);
    }
  }
}
*/

bool possible(std::vector<std::vector<int> >grid,int size){
    int i= size-1;
    int j= size-1;
    while(i != 0 && j != 0){
        //std::cout << i << ' ' << j << std::endl;
        if(i > 0 && j > 0){
            if(paths[i-1][j] && !paths[i][j-1]){
                i = i - 1;
            }else if(paths[i][j-1] && !paths[i-1][j]){
                j = j - 1;
            }else if(paths[i-1][j] && paths[i][j-1]){
                if(grid[i-1][j] > grid[i][j-1]){
                    i = i - 1;
                }else{
                    j = j - 1;
                }
            }else if(!paths[i-1][j] && !paths[i][j-1]){
                return false;
            }
        }else if(j==0){
            if(paths[i-1][j]){
                i = i - 1;
            }else{
                return false;
            }
        }else if(i==0){
            if(paths[i][j-1]){
                j = j - 1;
            }else{
                return false;
            }
        }else if(!paths[i-1][j] && !paths[i][j-1]){
            return false;
        }
    }
    return true;
}

int main(){
  int n,m;
  std::cin >> n >> m;
  std::vector<std::vector<int> >grid(n,std::vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      std::cin >> grid[i][j];
    }
  }
  for(int i=0;i<m;i++){
    int y,x,k;
    std::cin >>x>>y>>k;
    x--;y--;
    //addpts(/*paths,*/a,b,c,n);
    for (int i = 0; i <= k; i++) {
    // X1 = left of diamond, X2 = right of diamond.
        int x1     = (x - k) + i;
        int x2     = (x + k) - i;
        int yStart = y - i;
        int yEnd   = y + i;
        if (x1 < 0) {
            if (x2 >= n)
                continue;
            x1 = x2;
        } else if (x2 >= n) {
            x2 = x1;
        }
        if (yStart < 0)
            yStart = 0;
        if (yEnd >= n)
            yEnd = n-1;
        for (int y1 = yStart; y1 <= yEnd; y1++) {
            paths[x1][y1] = true;
            paths[x2][y1] = true;
        }
    }
  }
  paths[n-1][n-1] = true;
  paths[0][0] = true;
  for(int i=1;i<n;i++){
    if(paths[i][0] && paths[i-1][0]){
      grid[i][0] += grid[i-1][0];
    }
    if(paths[0][i] && paths[0][i-1]){
      grid[0][i] += grid[0][i-1];
    }
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(paths[i][j]){
        if(paths[i-1][j] && paths[i][j-1]){
            grid[i][j] += std::max(grid[i-1][j],grid[i][j-1]);
        }else if(paths[i-1][j]){
            grid[i][j] += grid[i-1][j];
        }else if(paths[i][j-1]){
            grid[i][j] += grid[i][j-1];
        }
      }
    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        std::cout << paths[i][j] << ' ';
    }
    std::cout << std::endl;
  }*/
  if(possible(grid,n)){
    //std::cout << possible(grid,n) << std::endl;
    std::cout << "YES" << std::endl;
    std::cout << grid[n-1][n-1] << std::endl;
  }else{
    std::cout << "NO" << std::endl;
  }
  return 0;
}
