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

int main(){
    //Input for the number books with the values
    int m;
    std::cin >> m;
    std::vector<int>books(m);
    std::vector<int>BIT(m+2);

    // std::ios_base::sync_with_stdio(false);
    for(int i=0;i<m;i++){
        std::cin>>books[i];
    }
    //Input for the dispatches made
    int n;
    std::cin >> n;
    std::vector<int>taken(n);

    for(int i=0;i<n;i++){
        int index;
        std::cin >> index;
        index--;
        index = bsearch(BIT, index);
        std::cout << books[index] << std::endl;
        BIT_ADD(BIT, index, -1);
    }

    return 0;
}
