#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

// Returns greatest common divisor of a and b.
static inline int gcd(int a, int b)
{
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Returns least common multiple of a and b.
static inline uint64_t lcm(int a, int b)
{
    a /= gcd(a, b);
    return (uint64_t) a * b;
}

static int solve(std::vector<int> caterpillars, int curCaterpillar,
        int numUsed, int curLcm, int n)
{
    if (curCaterpillar >= caterpillars.size())
        return 0;

    int val = caterpillars[curCaterpillar];
    int reached = 0;

    // Include current caterpillar:
    int64_t newLcm = lcm(curLcm, val);
    if (newLcm <= n) {
        if (numUsed & 1)
            reached -= n / newLcm;
        else
            reached += n / newLcm;
        reached += solve(caterpillars, curCaterpillar+1, numUsed+1, newLcm, n);
    }

    // Do not include current caterpillar:
    reached += solve(caterpillars, curCaterpillar+1, numUsed, curLcm, n);

    return reached;
}

int main (int argc, char const* argv[])
{
    long long n , k;
    std::cin >> n >> k;
    std::vector<int> caterpillars;
    std::vector<long long>v;
    int reached = 0;

    for(int i=0;i<k;i++){
        int a;
        std::cin >> a;
        caterpillars.push_back(a);
    }
    reached = solve(caterpillars, 0, 0, 1, n);
    std::cout << n - reached -1 << std::endl;
    return 0;
}
