#include "../include/Dijkstra.h"
#include <cstdlib>
#include<cstring>
#include<climits>
#include <queue>
#include "../include/comp.h"
#include<time.h>
#include<iostream>
Dijkstra::Dijkstra(vector<vector<pair<double,int> > > &graph1)
{
    graph = graph1;
    free(distance);
    distance = (double*)malloc(graph1.size()*sizeof(double));
    free(parent);
    parent = (int*)malloc(graph1.size()*sizeof(int));
    v = graph1.size();
}
void Dijkstra::initialize(){
    counter = 0;
    for(int i = 0 ; i < graph.size() ; i++){
        distance[i] = (double) INT_MAX;
    }
}
double * Dijkstra::getShortestPaths(int st){
    initialize();
    double t1  = clock();
    parent[st] = -1;
    distance[st] = 0;
    priority_queue < pair<double,int>,
     vector<pair<double,int> > ,comp >pq(comp(true)) ;
     pq.push(make_pair(0,st));
     pair<double,int> x ;
     while(!pq.empty() && x.first != INT_MAX){
         x = pq.top();pq.pop();
         if(distance[x.second] >= x.first){
             counter++;
             if(counter == v)
                break;
            for(int i = 0 ;  i < graph[x.second].size(); i++){
                if(distance[graph[x.second][i].second] > graph[x.second][i].first+x.first){
                    distance[graph[x.second][i].second] = graph[x.second][i].first+x.first;
                    parent[graph[x.second][i].second] = x.second;
                    pq.push(make_pair(graph[x.second][i].first+x.first,graph[x.second][i].second));
                }
            }
        }
     }
       cout<<"time is: "<<clock()-t1<<endl;
    return distance;
}
double Dijkstra::getShortestPath(int x , int y){
    getShortestPaths(x);
    return distance[y];
}
Dijkstra::~Dijkstra()
{
    //dtor
}
