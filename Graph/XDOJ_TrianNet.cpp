//
// Created by Chamb on 2021/12/31.
//
#include "iostream"
#include "string.h"
#define MAX_VEX 1000
using namespace std;

struct Graph{
    int vexNum,edgeNum;
    int edge[MAX_VEX][MAX_VEX];
};

void initGraph(Graph &g){
    memset(g.edge,0, sizeof(g.edge));
    g.edgeNum = 0;
    g.vexNum = 0;
}

void createGraph(Graph &g){
    cin>>g.vexNum>>g.edgeNum;
    for (int i = 0; i < g.edgeNum; ++i) {
        int head,tail;
        cin>>head>>tail;
        g.edge[head][tail] = 1;
        g.edge[tail][head] = 1;
    }
}

int visited[MAX_VEX] = {0};

void BFS(Graph &g, int v){
    //cout<<v<<" ";
    visited[v] = 1;
    for (int i = 1; i <= g.vexNum; ++i) {
        if (!visited[i] && g.edge[i][v]==1){
            BFS(g, i);
        }
    }
}

void BFSTraverse(Graph &g){
    int count = 0;
    for (int i = 1; i <= g.vexNum; ++i) {
        if (!visited[i]){
            BFS(g, i);
            count++;
        }
    }
    cout<<count-1;
}

int main(){
    Graph g;
    initGraph(g);
    createGraph(g);
    BFSTraverse(g);
    return 0;
}