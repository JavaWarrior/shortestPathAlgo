#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include<iostream>
using namespace std;
class Dijkstra
{
    public:
        Dijkstra(vector<vector<pair<double,int> > > &graph1);
        double* getShortestPaths(int start);
        double getShortestPath(int x , int y);
        virtual ~Dijkstra();

    protected:
    private:
        int v, *parent = NULL,counter = 0;double * distance = NULL;
        vector<vector<pair<double,int> > > graph;
        void initialize();

};

#endif // DIJKSTRA_H
