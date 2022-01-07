//
// Created by Chamb on 2021/12/24.
//

#include "iostream"
#include "string.h"

#define MAX_VEX 100
using namespace std;
struct Graph {
    int vexNum;
    int edge[MAX_VEX][MAX_VEX];
};

void createGraph(Graph &g) {
    cin >> g.vexNum;
    memset(g.edge, 0, sizeof(g.edge));
    for (int i = 1; i <= g.vexNum; ++i) {
        for (int j = 1; j <= g.vexNum; ++j) {
            cin >> g.edge[i][j];
        }
    }
}

int visited[MAX_VEX] = {0};

void BFS(Graph &g, int v) {
    cout << v << " ";
    visited[v] = 1;
    for (int i = 1; i <= g.vexNum; ++i) {
        if (!visited[i] && g.edge[i][v] > 0) {
            visited[i] = 1;
            BFS(g, i);
        }
    }
}

int count = 0;//连通分量数

void BFSTraverse(Graph &g) {
    for (int i = 1; i <= g.vexNum; ++i) {
        if (!visited[i]) {
            BFS(g, i);
            count++;
            //如果这个图是连通的，那么第一次DFS就可以遍历完所有结点
            //但如果不是联通的，那么就需要再次DFS，因此count++
            //用了几次DFS就是几个连通分量
        }
    }
}

int main() {
    Graph g;
    createGraph(g);
    BFSTraverse(g);
    cout << endl;
    cout << count;
}
