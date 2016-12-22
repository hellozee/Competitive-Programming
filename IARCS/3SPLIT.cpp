//Author  : Kuntal Majumder
//Problem : 3SPLIT

#include <iostream>
#include <vector>
#include <utility>

//This is a typical leaf cutting problem , where you have to divide the whole tree into 3 parts
//Now if there are n edges you can cut them in nC2 ways
//First you have to find out which one are leaves , in simple words you have to find out an order in which you can cut or 
//you can say put 2 cuts , now if a leaf is not cut it must be added to its parent
//Take the given example
// 1        5
//  \      /
//   3 -- 4
//  /      \
// 2        6
// Now the order to cut the tree will be first , the leaves that is nodes with 1 edges
// which is 1 , 2 ,5 , 6
// 3 and 4 remain , let us add them to the queue , 1(3) , 2(3) ,5(4),6(4),3(4),4(null) , the nodes in brackets are their parents
// Ok as far as the solution goes lets cut the 3(4) edge and 5(4) edge
// It will go like this:
// First we will traverse through the genarated array , we are no cutting 1(3) so
//          5
//         /
//  1+3 -- 4
//  /      \
// 2        6
// We are also no going to cut 2(3)
//            5
//           /
// 2+1+3 -- 4
//           \
//            6
// Ok we are cutting 5(4)
//            5
//           
// 2+1+3 -- 4
//           \
//            6
// We are not going to cut 6(4)
//            5
//           
// 2+1+3 -- 4+6
// We are going to cut the 3(4) edge
// Hence the graph is divided like this
// (2+1+3)--(4+6)--(5) , which is the solution , but before looking at the solution , I think you must try it once , now

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
