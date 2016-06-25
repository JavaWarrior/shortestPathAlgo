#include <algorithm>
#include <string>
#include <complex>
#include <cassert>
#include <memory>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cctype>
#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
using namespace std;
#include "../include/BellmanNormal.h"
double BellmanNormal::getShortestPath(int start ,int end){
    getShortestPaths(start);
    return distance[end];
}

void BellmanNormal::initialize(){
    for(int i = 0 ; i < graph.size() ; i++){
        distance[i] = (double) INT_MAX;
    }
    v= graph.size();
    isNegative = false;
}
BellmanNormal::BellmanNormal(vector<vector<pair<double,int> > > graph1)
{
    graph = graph1;
    free(distance);
    distance = (double*)malloc(graph1.size()*sizeof(double));
    free(parent);
    parent = (int*)malloc(graph1.size()*sizeof(int));
}
double *BellmanNormal::getShortestPaths(int start){
    initialize();
    double t1 = clock();
    distance[start] = 0;parent[start] = -1;
    for(int j = 0 ; j < v -1 ; j++){
        bool f = false;
        for(int k = 0 ; k < v ;k++){
            for(int i = 0 ; i < graph[k].size() ; i++){
                if(distance[graph[k][i].second]> distance[k]+graph[k][i].first){
                    distance[graph[k][i].second] =  distance[k]+graph[k][i].first;
                    parent[graph[k][i].second] =  k;
                    f = true;
                }
            }
        }
        if(!f){
            break;
        }
    }
    bool f = false;
    for(int k = 0 ; k < v ;k++){
        for(int i = 0 ; i < graph[k].size() ; i++){
            if(distance[graph[k][i].second]> distance[k]+graph[k][i].first){
                f = true;
                break;
            }
        }
        if(f){
            break;
        }

    }
    if(f){
            isNegative = true;
        }

    cout<<"time is: "<<clock()-t1<<endl;
    return distance;
}
BellmanNormal::~BellmanNormal()
{
    //dtor
}
