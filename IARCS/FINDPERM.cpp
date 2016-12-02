#include <iostream>
#include <vector>

static inline int BIT_GET(const std::vector<int> &BIT, int i)
{
    int ret = 0;
    i++;
    while (i > 0) {
        ret += BIT[i-1];
        i -= (i & -i);
    }
    return ret;
}

static inline void BIT_ADD(std::vector<int> &BIT, int i, int val)
{
    int max = BIT.size();
    i++;
    while (i < max)
    {
        BIT[i-1] += val;
        i += (i & -i);
    }
}

int bsearch(const std::vector<int> &BIT, int index)
{
    int low  = 0;
    int high = BIT.size()-1;

    while (low <= high) {
        int mid    = low + ((high-low)>>1);
        int midVal = mid + BIT_GET(BIT, mid);

        if (midVal >= index)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int>inv(n);
    std::vector<int>original(n);
    std::vector<int>BIT(n);

    for (int i=0;i<n;i++)
        std::cin >> inv[i];

    for (int i=n-1;i>=0;i--) {
        int index = bsearch(BIT, inv[i]);
        original[n - 1 - index] = i + 1;
        BIT_ADD(BIT, index, -1);
    }

    for (int i=0;i<n;i++)
        std::cout << original[i] << " ";

    return 0;
}
