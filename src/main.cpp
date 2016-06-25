#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include"../include/Dijkstra.h"
#include"../include/BellmanFord.h"
#include "../include/BellmanNormal.h"
#include<dirent.h>
using namespace std;
bool eflag = false,negFlag = false;    int v , e;
vector<string> files;
char * fileName ="dumpy";
vector< vector< pair< double, int> > > graph;
bool exitFlag=  false;
void selectDirec(){
    files.clear();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (".")) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        if(opendir(ent->d_name) == NULL){
            files.push_back(ent->d_name);
        }
      }
      closedir (dir);
    } else {
    eflag = true;
      cout<<"directory error"<<endl;
    }
    files.push_back("exit");
}
void selectFile(){
    selectDirec();
    cout<<"choose file"<<endl;
    for(int i = 0 ; i < files.size() ; i++){
        cout<<i+1<<" : "<<files[i]<<endl;
    }
    int choice = 0;
    cout<<"enter file number"<<endl;
    cin>>choice;
    if(choice == files.size()){
        exitFlag = true;
        return;
    }
    choice--;
    fileName = const_cast<char*>(files[choice].c_str());

}
void readGraph(){
     cout<<fileName<<":"<<endl;
    ifstream ifile; ifile.open(fileName);
    if(!ifile.is_open()){
        cout<<"no file with the name specified"<<endl;
        eflag = true;
        return;
    }
    eflag = false;
    ifile>>v>>e;
    graph.clear();
    graph.resize(v);
    for(int i = 0 ; i < e ; i++){
        int  f,t;double w;
        ifile>>f>>t>>w;
        if(w < 0)
            negFlag = true;
        graph[f].push_back(make_pair(w,t));
    }

}
void printRet(double * ret,int z){
    ofstream ofile("output.txt",ios::app);
    if(z == 1){
        ofile<<"bellman-norm"<<endl;
    }
    if(z == 2)
        ofile<<"bellman-moore"<<endl;
    if(z == 3)
        ofile<<"dijkstra"<<endl;
    ofile<<"[ ";
    for(int i = 0 ; i <v ; i++){
        ofile<<ret[i]<<" ";
    }ofile<<"]"<<endl;
    cout<<ret[v-1]<<endl;
}
int main()
{
    remove("output.txt");
    while(!exitFlag){
        selectFile();
        if(eflag || exitFlag)
            continue;
        readGraph();
        if(eflag)
            continue;
        cout<<"nodes: "<<v<<" edges: "<<e<<endl;
        BellmanNormal bn (graph);
        cout<<"Bellman-Ford:"<<endl;
        printRet(bn.getShortestPaths(0),1);
        if(bn.isNegative){
            cout<<"negative cycles... negative cycles everywhere"<<endl;
            return 0;
        }
        BellmanFord bf(graph);
        cout<<"Bellman-Ford-moore:"<<endl;
        printRet(bf.getShortestPaths(0),2);
        //bf.getShortestPaths(0);

        if(negFlag)
            return 0;

        Dijkstra DJFeloo (graph);
        cout<<"dijkstra:"<<endl;
        printRet(DJFeloo.getShortestPaths(0),3);
        //DJFeloo.getShortestPaths(0);

    }
    return 0;
}
