#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include<vector>
#include<iostream>
 using namespace std;

class BellmanFord
{
    public:
        BellmanFord(vector<vector<pair<double,int> > > graph1);
        double *getShortestPaths(int start),getShortestPath(int start,  int end);
        virtual ~BellmanFord();
    protected:
    private:
        vector<vector<pair<double,int> > > graph;
        double *distance = NULL;int *parent = NULL;
        void initialize();
};

#endif // BELLMANFORD_H
