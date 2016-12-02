#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main (int argc, char const* argv[])
{
    int n;
    std::cin >> n;
    int difference[n];
    int total = 0;
    for(int i=0;i<n;i++){
        int a,b;
        std::cin>>a >>b;
        difference[i] = std::abs(a-b);
        total += difference[i];
    }

    // Find each reachable sum up to total/2.
    int  max = total/2;
    std::vector<bool>arr(max+1);
    arr[0] = true;
    for (int i = 0; i < n; i++) {
        int val = difference[i];
        for (int j = max - val; j >= 0; j--) {
            if (arr[j])
                arr[j+val] = true;
        }
    }

    // Find the max reachable sum.  For that sum, print the difference between
    // one child's sum (i) and the other's (total - i).  Since i is always
    // less than or equal to (total - i), the difference will be total - i - i.
    for (int i = max; i >= 0; i--) {
        if (arr[i]) {
            std::cout << total - i - i << std::endl;
            break;
        }
    }
    return 0;
}
