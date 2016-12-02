#include <iostream>
#include <vector>
#include <algorithm>

int swap(std::vector<int>highshelf,std::vector<int>lowshelf,int n,int swaps){
    int skew = highshelf[0]+lowshelf[0]; //the current skew
    if(swaps == 0){ //if no more swaps allowed then return the skew
        return skew;
    }
    int s = swaps;
    for(int i=n-1;i>=0;i--){
        //std::cout << i << " ";
        if(lowshelf[0] > highshelf[i]){ //comparing the maximum of a shelf to the elements of other from the end
            int temp =lowshelf[0];
            lowshelf[0] = highshelf[i];
            highshelf[i] = temp;
            swaps--; // the element is swapped , need to sort that again
            sort(highshelf.begin(),highshelf.end(),std::greater<int>());
            sort(lowshelf.begin(),lowshelf.end(),std::greater<int>());
            //std::cout << i << std::endl;
            break;
        }
    }
    // if it has achieved minimum skew otherwise go on
    if(s == swaps){
        swaps--;
    }
    return swap(highshelf,lowshelf,n,swaps);
}

int main(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int>firstShelf(n);
    std::vector<int>secShelf(n);

    for(int i=0;i<n;i++){   
        std::cin >> firstShelf[i];
    }

    for(int i=0;i<n;i++){   
        std::cin >> secShelf[i];
    }

    //Sorting for easy swapping
    sort(firstShelf.begin(),firstShelf.end(),std::greater<int>());
    sort(secShelf.begin(),secShelf.end(),std::greater<int>());

    //Calculating by taking both as high as well as low
    int max1 = swap(firstShelf,secShelf,n,k);
    int max2 = swap(secShelf,firstShelf,n,k);

    if(max1 > max2){
        std::cout << max2 << std::endl;
    }else{
        std::cout << max1 << std::endl;
    }

    return 0;
}
//5 2 3 5 2 7 1 14 2 3 10 4
