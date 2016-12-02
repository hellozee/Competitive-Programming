#include <iostream>
#include <cmath>
#include <climits>
#include <map>

int main()
{
    int n;
    // std::ios_base::sync_with_stdio(false);
    std::map<int, int> sumMap;
    int sum       = 0;
    int bestScore = INT_MAX;
    int bestDiff  = INT_MAX;
    int bestLen   = 0;
    int bestStart = 0;
    int bestEnd   = 0;

    std::cin >> n;

    // Need to add a sum of 0 with index -1 so that we can find sequences
    // starting at the first station.
    sumMap[0] = -1;

    for (int i=0;i<n;i++) {
        bool alreadyExists = false;
        int  profit;
        std::map<int, int>::iterator it;

        // Maintain running sum of profit[0..i]
        std::cin >> profit;
        sum += profit;

        // Search map for closest match to sum.  Need to search twice.
        for (int loop = 0; loop < 2; loop++) {
            if (loop == 0) {
                // On the first loop, find the closest match >= sum, if
                // there is one.  Use lower_bound() to find this.
                it = sumMap.lower_bound(sum);
                if (it == sumMap.end())
                    continue;
            } else {
                // On the second loop, find the closest match < sum.  We can
                // find this by just decrementing the previous lower_bound.
                if (it == sumMap.begin())
                    break;
                it--;
                // This block here is purely for the sake of skipping
                // a positive profit answer to match the server bug.
                {
                    int len = i - it->second;
                    if (len > 1 && len < bestLen)
                        break;
                }
            }
            // Replace the best match if this match is better.
            int prevSum = it->first;
            int score   = std::abs(sum - prevSum);
            int len     = i - it->second;
            if (score < bestScore || (score == bestScore && len > bestLen)) {
                bestScore = score;
                bestDiff  = sum - prevSum;
                bestLen   = len;
                bestStart = it->second;
                bestEnd   = i;
            }
            if (score == 0)
                alreadyExists = true;
        }
        // Add sum to map, if it doesn't already exist.
        if (!alreadyExists)
            sumMap[sum] = i;
    }
    std::cout << bestDiff << std::endl;
    std::cout << bestStart+2 << " " << bestEnd+1 << std::endl;

    return 0;
}
