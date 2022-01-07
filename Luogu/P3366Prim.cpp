//
// Created by Chamb on 2021/12/25.
//
#include <cstring>
#include "iostream"

#define MAX_VEX 100
#define INFINITY 10000
using namespace std;
struct Graph {
    int vexNum;
    int edgeNum;
    int edge[MAX_VEX][MAX_VEX];
};

void initGraph(Graph &g) {
    memset(g.edge, INFINITY, sizeof(g.edge));
    for (int i = 0; i < MAX_VEX; ++i) {
        g.edge[i][i] = 0;
    }
    g.vexNum = g.edgeNum = 0;
}

void createGraph(Graph &g) {
    cin >> g.vexNum >> g.edgeNum;
    for (int i = 0; i < g.edgeNum; ++i) {
        int head, tail, cost;
        cin >> head >> tail >> cost;
        g.edge[head][tail] = cost;
        g.edge[tail][head] = cost;
    }
}

struct closeEdge {
    int adjvex;
    int lowCost;
};

void Prim(Graph &g, int v) {
    //初始化边集
    int minPath = 0;
    closeEdge c[MAX_VEX];
    for (int i = 1; i <= g.vexNum; ++i) {
        c[i].adjvex = v;
        c[i].lowCost = g.edge[v][i];
    }

    for (int i = 0; i < g.vexNum - 1; ++i) {
        int min = INFINITY;
        int minVex;
        for (int j = 1; j <= g.vexNum; ++j) {
            if (c[j].lowCost != 0 && c[j].lowCost < min) {
                min = c[j].lowCost;
                minVex = j;
            }
        }
//        cout << c[minVex].adjvex << "," << minVex << " ";
        minPath += min;

        for (int j = 1; j <= g.vexNum; j++) {
            if (c[j].lowCost != 0 && c[j].lowCost > g.edge[j][minVex]) {
                c[j].lowCost = g.edge[j][minVex];
                c[j].adjvex = minVex;
            }
        }
    }
    cout<< minPath<<endl;
}

int main(){
    Graph g;
    initGraph(g);
    createGraph(g);
    Prim(g,1);
}
