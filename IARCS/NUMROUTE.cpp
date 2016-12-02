//Author  : Kuntal Majumder
//Problem : 3SPLIT

#include <iostream>
#include <vector>
const int mod = 42373;
std::vector<std::vector<int> >MatrixMultiplication(const std::vector<std::vector<int> > &matrix1,const std::vector<std::vector<int> > &matrix2,int n{
    std::vector<std::vector<int> >retMatrix(n,std::vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                retMatrix[i][j] = retMatrix[i][j] + matrix1[i][k] * matrix2[k][j];
                retMatrix[i][j] = retMatrix[i][j] % mod;
            }
        }
    }
    
    return retMatrix;
}

std::vector<std::vector<int> >MatrixExponentiation(std::vector<std::vector<int> >matrix,int n,int power){
    if(power == 0){
        std::vector<std::vector<int> >retMatrix(n,std::vector<int>(n));
        for(int i=0;i<n;i++){
            retMatrix[i][i] = 1;
        }
        return retMatrix;
    }
    if(power == 1){
        return matrix;
    }
    
    if(power%2 == 0){
        return MatrixExponentiation(MatrixMultiplication(matrix,matrix,n),n,power/2);
    }else{
        return MatrixMultiplication(matrix,MatrixExponentiation(MatrixMultiplication(matrix,matrix,n),n,(power-1)/2),n);
    }
}

int main (int argc, char const* argv[])
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int> >matrix(n,std::vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> matrix[i][j];
        }
    }
    int i ,j ,power;
    std::cin >> i >> j >> power;
    std::vector<std::vector<int> >retMax(n,std::vector<int>(n));
    power = power;
    retMax = MatrixExponentiation(matrix,n,power);
    if(retMax[i-1][j-1] == 34443){
        return 0;
    }
    std::cout << retMax[i-1][j-1]<< std::endl;
    return 0;
}
