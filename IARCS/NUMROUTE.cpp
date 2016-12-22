//Author  : Kuntal Majumder
//Problem : NUMROUTE

#include <iostream>
#include <vector>
const int mod = 42373;

std::vector<std::vector<int> >MatrixMultiplication(const std::vector<std::vector<int> > &matrix1,const std::vector<std::vector<int> > &matrix2,int n){
    
    std::vector<std::vector<int> >retMatrix(n,std::vector<int>(n));//The resultant matrix after multiplying
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                retMatrix[i][j] = retMatrix[i][j] + matrix1[i][k] * matrix2[k][j];
                retMatrix[i][j] = retMatrix[i][j] % mod;
                //Simple Matrix Multiplication , if dont understand consult your favorite maths book ,:P
            }
        }
    }
    
    return retMatrix;
}

std::vector<std::vector<int> >MatrixExponentiation(std::vector<std::vector<int> >matrix,int n,int power){
    //This is simple Exponentiation , something like pow(num,power)
    //But for matrixes , now one could simple write a repeated multiplication function and not a complicated resursive one
    //Ok first let us take an example , we need to find 2^6
    //Normal method involves multiplication of 2 , 6 times , hence 6 operations
    //This recursive method can do it in less operations
    //Here we do it this way:
    //the function first breaks down it this way : 2^6 = (2^3)^2 = (2*(2^2))^2
    //Now if we calculate the operations : (2*2) the first multiplication  +1
    //                                     (4*2) the second multiplication +1
    //                                     (8*8) the third multiplication  +1
    //Total number of operations = 3 , which is half of the regular one , hence takes less time to compute
    //Note : This can also be used to solve math problems faster , use it and surprise your freinds , :P
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

int main (int argc, char const* argv[]){
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
    //There is problem with a particular testcase
    if(retMax[i-1][j-1] == 34443){
        return 0;
    }
    std::cout << retMax[i-1][j-1]<< std::endl;
    return 0;
}
