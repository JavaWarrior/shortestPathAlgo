#include "../include/BellmanFord.h"
#include <cstdlib>
#include<cstring>
#include<climits>
#include <queue>
#include "../include/comp.h"
#include<iostream>
#include <time.h>
BellmanFord::BellmanFord(vector<vector<pair<double,int> > > graph1)
{
    graph = graph1;
    free(distance);
    distance = (double*)malloc(graph1.size()*sizeof(double));
    free(parent);
    parent = (int*)malloc(graph1.size()*sizeof(int));
}
double *BellmanFord::getShortestPaths(int start){
    initialize();
    double t1 = clock();
    queue <pair<double,int> > vec;
    distance[start] = 0;parent[start] = -1;
    vec.push(make_pair(0,start));
    pair<double,int> x;
    while(!vec.empty()){
        x = vec.front();vec.pop();
        if(distance[x.second] >= x.first){
            for(int i = 0 ; i < graph[x.second].size() ; i++){
                if(distance[graph[x.second][i].second]> x.first+graph[x.second][i].first){
                    distance[graph[x.second][i].second] =  x.first+graph[x.second][i].first;
                    parent[graph[x.second][i].second] =  x.second;
                    vec.push(make_pair(distance[graph[x.second][i].second],graph[x.second][i].second));
                }
            }
        }
    }
    cout<<"time is: "<<clock()-t1<<endl;
    return distance;
}
double BellmanFord::getShortestPath(int start ,int end){
    getShortestPaths(start);
    return distance[end];
}
void BellmanFord::initialize(){
    for(int i = 0 ; i < graph.size() ; i++){
        distance[i] = (double) INT_MAX;
    }
}
BellmanFord::~BellmanFord()
{
    //dtor
}
