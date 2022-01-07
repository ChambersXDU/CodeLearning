//
// Created by Chamb on 2021/12/31.
//
#include "iostream"
#include "string.h"
#include "queue"

#define MAX_VEX 100
using namespace std;
struct Graph {
    int vexNum,edgeNum;
    int edge[MAX_VEX][MAX_VEX];
};

void createGraph(Graph &g) {
    cin >> g.vexNum>>g.edgeNum;
    memset(g.edge, 0, sizeof(g.edge));
    for (int i = 0; i < g.edgeNum; ++i) {
        int head,tail;
        cin>>head>>tail;
        g.edge[head][tail] = 1;
        g.edge[tail][head] = 1;
    }
}

int visited[MAX_VEX] = {0};

void BFS(Graph &g, int v) {
    //cout << v << " ";
    visited[v] = 1;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 1; i <= g.vexNum; ++i) {
            if (!visited[i] && g.edge[p][i] == 1) {
                //cout << i << " ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int count = 0;//连通分量数

void BFSTraverse(Graph &g) {
    for (int i = 1; i <= g.vexNum; ++i) {
        if (!visited[i]) {
            BFS(g, i);
            count++;
        }
    }
}

int main() {
    Graph g;
    createGraph(g);
    BFSTraverse(g);
    cout << count-1;
}

