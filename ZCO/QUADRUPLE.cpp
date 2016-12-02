#include <unordered_map>
#include <iostream>
#include <vector>

int main(void){
    int n     = 0;
    int total = 0;

    std::cin >> n >> total;

    // Read in individual numbers.
    std::vector<int> num(n);
    for (int i=0;i<n;i++)
        std::cin >> num[i];

    std::unordered_map<int, int> sumCount;

    long long quadCount = 0;
    // At each iteration i, sumCount[sum] holds the number of pairs (j,k) where:
    //
    // 1) j < i
    // 2) k < i
    // 3) num[j] + num[k] = sum
    for (int i=0;i<n;i++) {
        int num1 = num[i];
        // In this loop, we find quads that sum to total, where two of the
        // numbers are num[i] and num[j], and the other two numbers were
        // from pairs with indices less than i:
        for (int j=i+1;j<n;j++) {
            int sum = num1 + num[j];
            quadCount += sumCount[total - sum];
        }
        // In this loop, we add all pairs with index (i,j) to sumCount,
        // where j < i.  This makes sumCount ready for i+1.
        for (int j=0; j < i; j++) {
            sumCount[num1 + num[j]]++;
        }
    }
    std::cout << quadCount << std::endl;
}


