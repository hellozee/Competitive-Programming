#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef struct timef{
    int start;
    int end;
}timef;

bool comp1(const timef &t1, const timef &t2){
    return t1.start < t2.start;
}

bool comp2(const timef &t1, const timef &t2){
    return t1.end < t2.end;
}

int main(){
    int contests , fromHoles, toHoles;
    std::cin >> contests >> fromHoles >> toHoles;
    std::vector<timef>cons(contests);
    for(int i=0;i<contests;i++){
        std::cin >> cons[i].start >> cons[i].end;
    }
    std::vector<int>fromtms(fromHoles);
    std::vector<int>totms(toHoles);
    for(int i=0;i<fromHoles;i++){
        std::cin >> fromtms[i];
    }
    for(int i=0;i<toHoles;i++){
        std::cin >> totms[i];
    }

    sort(fromtms.begin(),fromtms.end());
    sort(totms.begin(),totms.end());
    sort(cons.begin(),cons.end(),comp1);

    int i=0,counter = 0;

    for(int i=0;i<contests;i++){
        if(cons[i].start >= fromtms[0]){
            break;
        }
        cons[i].start = -1;
    }

    while(counter < contests && i < fromHoles){
        if(cons[counter].start == -1){
            counter++;
            continue;
        }
        if(fromtms[i] <= cons[counter].start){
            i++;
        }else{
            if(i > 0)
                //std::cout << fromtms[i-1] << std::endl;
                cons[counter].start = fromtms[i-1];
            counter++;
        }
    }

    //std::cout << counter << std::endl;
    sort(cons.begin(),cons.end(),comp2);

    for(int i=contests-1;i>=0;i--){
        if(cons[i].end <= totms[toHoles-1]){
            break;
        }
        //std::cout << cons[i].end << std::endl;
        cons[i].end = -1;
    }
    i=0;counter=0;
    while(counter < contests && i < toHoles){
        if(cons[counter].end == -1){
            break;
        }
        if(totms[i] < cons[counter].end){
            i++;
        }else{
            //std::cout << totms[i] << std::endl;
            cons[counter].end = totms[i];
            counter++;
        }
    }

    //std::cout << counter << std::endl;

    int minimum = INT_MAX;

    for(int i=0;i<contests;i++){
        //std::cout << cons[i].start << ' ' << cons[i].end << std::endl;
        if(cons[i].start == -1 || cons[i].end == -1){
            continue;
        }

        int temp = cons[i].end - cons[i].start + 1;
        //std::cout << cons[i].end << ' ' << cons[i].start << ' ' << i << std::endl;
        if(temp < minimum){
            minimum = temp;
        }
    }

    std::cout << minimum << std::endl;

    return 0;
}
