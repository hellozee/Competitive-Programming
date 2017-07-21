//Author  : Kuntal Majumder
//Problem : 3SPLIT

#include <iostream>
#include <vector>
#include <utility>


int main(){
    //Inputs
    int stations,total=0;
    std::cin >> stations;
    std::vector<int>weights(stations);
    for(int i=0;i<stations;i++){
        std::cin >> weights[i]; // weights of respective stations
        total += weights[i];
    }
    std::vector<std::pair<int,int> >connections(stations-1); // vector for recording paths    
    std::vector<int>conNums(stations,0);// vector for recording number of connections    
    for(int i=0;i<stations-1;i++){
        std::cin >> connections[i].first >> connections[i].second; //first = station where path starts , second = where it ends
        connections[i].first--;connections[i].second--;
        conNums[connections[i].first]++;conNums[connections[i].second]++;
    }
    std::vector<std::pair<int,int> >leafOrder(stations-1); //vector for maintaining a leaf order
    //Inputs and declarations end here    
    //Now gotta arrange an order to cut the leaves    
    for(int i=0;i<stations-1;i++){
        int from;
        for(int j=0;j<stations;j++){
            if(conNums[j] == 1 || conNums[j] == 0){
                from = j;
                break;
            }
        }
        leafOrder[i].first = from;
        conNums[from] = -1;        
        for(int j=0;i<stations-1;j++){
            if(connections[j].first == from || connections[j].second == from){
                int to = connections[j].first;
                if(to == from){
                    to = connections[j].second;
                }
                //That was a smart one
                conNums[to]--;//one edge taken
                connections[j].first = -1;
                connections[j].second = -1;
                leafOrder[i].second = to;
                break;
            }
        }
    }    
    int leastMaxweight = total;    
    for(int i=0;i<stations-1;i++){
        int node1 = leafOrder[i].first;
        int weight1 = weights[node1];       
        std::vector<int>weightsCopy(weights);//gotta copy it , time to get messy
        for(int j=i+1;j<stations;j++){
            int node2 = leafOrder[j].first;
            int weight2 = weightsCopy[node2];
            int weight3 = total - weight1 - weight2;
            int max = weight1;
            if(weight2 > max){
                max = weight2;
            }
            if(weight3 > max){
                max = weight3;
            }
            //Another piece of smartness 
            if(max < leastMaxweight){
                leastMaxweight = max;
            }
            weightsCopy[leafOrder[j].second] += weight2; //adding the weight of the vertex to its connected part
        }
        weights[leafOrder[i].second] += weight1;//adding the weight of the vertex to its connected part
    }
    std::cout << leastMaxweight << std::endl;
    return 0;
}
