//
// Created by Chamb on 2021/12/18.
//
#include "iostream"
#include "algorithm"
#include "string.h"
#define MAX_VEX 50
#define INFINITY 10000
using namespace std;

struct Graph{
    int vex[MAX_VEX];
    int edge[MAX_VEX][MAX_VEX];
    int vexNum,edgeNum;
};

void initGraph(Graph &g){
    memset(g.edge,INFINITY,sizeof (g.edge));
    g.vexNum = g.edgeNum = 0;
}

void createGraph(Graph &g){
    cout<<"input vexNUm and edgeNum:"<<endl;
    cin>>g.vexNum>>g.edgeNum;
    cout<<"input head,tail,and cost of edges";
    for (int i = 0; i < g.edgeNum; ++i) {
        int tail,head,cost;
        cin>>head>>tail>>cost;
        g.edge[head][tail] = cost;
        g.edge[tail][head] = cost;
    }
}


int visited[MAX_VEX] = {0};
//对于连通图来说用这个就够了
void DFS(Graph g,int v){
    cout<<v<<" ";
    visited[v] = 1;
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i] && g.edge[v][i]<INFINITY){
            visited[i] = 1;
            DFS(g,i);
        }
    }
}

void DFSTraverse(Graph g){
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i]){
            DFS(g,i);
        }
    }
}

int main(){
    Graph g;
    initGraph(g);
    createGraph(g);
    DFS(g,0);
}

