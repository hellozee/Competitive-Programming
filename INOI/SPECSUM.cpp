#include <iostream>
#include <vector>
#include <climits>

int main(){
    int n;
    std::cin >> n;
    std::vector<long long int>firstSeq(n);
    std::vector<long long int>secSeq(n);
    std::vector<long long int>cm(n,0);
    bool notFirst = false;
    long long int max = INT_MIN;
    for(int i=0;i<n;i++){
        std::cin >> firstSeq[i];
        max = std::max(max,firstSeq[i]);
        if(notFirst){
            max = std::max(max,firstSeq[i]+firstSeq[i-1]);
        }
        notFirst = true;
    }
    std::cin >> secSeq[0];
    cm[0] = secSeq[0];
    for(int i=1;i<n;i++){
        std::cin >> secSeq[i];
        cm[i] = secSeq[i] + cm[i-1];
    }
    std::vector<long long int>sums(n,0);
    std::vector<long long int>differences(n,0);

    differences[0] = cm[0] - firstSeq[0];
    for(int i=1;i<n;i++){
        differences[i] = std::min(differences[i-1],cm[i]-firstSeq[i]);
    }

    sums[n-1] = firstSeq[n-1] + (n-2 >= 0) ? cm[n-2] : 0;
    for(int i=n-2;i>=0;i--) {
        sums[i] = std::max(sums[i+1],firstSeq[i]+((i-1 >= 0) ? cm[i-1] : 0));
    }

    std::vector<long long int> frontBest(n,0);
    std::vector<long long int> reverseBest(n,0);

    frontBest[0] = firstSeq[0];
    for(int i=1;i<n;i++){
        frontBest[i] = std::max(frontBest[i-1],firstSeq[i] + cm[i-1]);
    }
    for(int i=0;i<n;i++){
        max = std::max(max,sums[i]-differences[i]);
    }

    for(int i=n-2;i>=0;i--){
        reverseBest[i] = std::max(reverseBest[i+1],firstSeq[i]+cm[n-1]-cm[i]);
    }

    for(int i=1;i<n;i++){
        max = std::max(max,frontBest[i-1]+reverseBest[i]);
    }

    std::cout << max << std::endl;
    return 0;
}
