//
// Created by Chamb on 2021/12/19.
//

#include "iostream" //for I/O & test
#include "string.h"//for "memset"

#define MAX_VEX 10
#define INFINITY 10000
using namespace std;
//图的表示
struct Graph {
    int vexNum, edgeNum;
    int vex[MAX_VEX];
    int edge[MAX_VEX][MAX_VEX];
};

//图的初始化
void initGraph(Graph &g) {
    memset(g.vex, 0, sizeof(g.vex));
    memset(g.edge, INFINITY, sizeof(g.edge));
    g.edgeNum = g.vexNum = 0;
}

void createGraph(Graph &g) {
    cout << "please input vexNum & edgeNum:" << endl;
    cin >> g.vexNum >> g.edgeNum;
    cout << "please input the head,tail and lowCost of edge" << endl;
    for (int i = 0; i < g.edgeNum; ++i) {
        int head, tail, cost;
        cin >> head >> tail >> cost;
        g.edge[head][tail] = cost;
        g.edge[tail][head] = cost;
    }
}

int D[MAX_VEX][MAX_VEX];
int path[MAX_VEX][MAX_VEX];

void Floyd(Graph &g) {

    //初始化D矩阵
    for (int i = 0; i < g.vexNum; ++i) {
        for (int j = 0; j < g.vexNum; ++j) {
            if (i == j) {
                D[i][i] = 0;
            } else {
                D[i][j] = g.edge[i][j];
            }
            path[i][j] = -1;
        }
    }

    //迭代
    for (int i = 0; i < g.vexNum; ++i) {

        for (int j = 0; j < g.vexNum; ++j) {
            for (int k = 0; k < g.vexNum; ++k) {
                if (D[j][i] + D[i][k] < D[j][k]) {
                    D[j][k] = D[j][i] + D[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
}

void getPath(int end, int start) {
    cout << start;
    int k = path[start][end];
    while (k != end) {
        cout << "->" << k;
        k = path[k][end];
    }
    cout << "->" << end;
}

int main() {
    Graph g;
    initGraph(g);
    createGraph(g);
    Floyd(g);
    int end = 4,start = 1;
    getPath(end, start);
    cout<<endl;
    cout<<"closest length:"<<D[start][end];
}

