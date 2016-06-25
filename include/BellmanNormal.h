#ifndef BELLMANNORMAL_H
#define BELLMANNORMAL_H


class BellmanNormal
{
    public:
        BellmanNormal(vector<vector<pair<double,int> > > graph1);
        double *getShortestPaths(int start),getShortestPath(int start,  int end);
        bool isNegative = false;int v = 0;
        virtual ~BellmanNormal();
    protected:
    private:
        vector<vector<pair<double,int> > > graph;
        double *distance = NULL;int *parent = NULL;
        void initialize();
};

#endif // BELLMANNORMAL_H
