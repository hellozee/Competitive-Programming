#include <vector>
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>nums(n);
    for(int i=0;i<n;i++){
        std::cin >> nums[i];
    }
    // ispal[i][j] is true if nums[i..j] is a palindromic sequence.
    std::vector<std::vector<bool> > ispal(n,std::vector<bool>(n,false));

    // Find all palindromic sequences whose middle is exactly on a number.
    for (int i=0;i<n;i++) {
        int jmax = i;
        if (n-i-1 < jmax)
            jmax = n-i-1;
        for (int j=0;j<=jmax;j++) {
            if (nums[i-j] == nums[i+j])
                ispal[i-j][i+j] = true;
            else
                break;
        }
    }
    // Find all palindromic sequences whose middle is in between two numbers.
    for (int i=0;i<n;i++) {
        int jmax = i;
        if (n-i-2 < jmax)
            jmax = n-i-2;
        for (int j=0;j<=jmax;j++) {
            if (nums[i-j] == nums[i+j+1])
                ispal[i-j][i+j+1] = true;
            else
                break;
        }
    }

    // minNum[i] holds the minimum number of palindromic sequences to construct
    // nums[0..i-1].
    std::vector<int> minNum(n+1, n+1);
    minNum[0] = 0;

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int score;
            if (ispal[i][j]) {
                score = minNum[i] + 1;
                if (score < minNum[j+1])
                    minNum[j+1] = score;
            }
        }
    }

    std::cout << minNum[n] << std::endl;

    return 0;
}
