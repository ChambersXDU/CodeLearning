//
// Created by Chamb on 2021/12/19.
//

#include "iostream" //for I/O & test
#include "string.h"//for "memset"
#include "stack"

#define MAX_VEX 100
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
    memset(g.edge, 0, sizeof(g.edge));
    g.edgeNum = g.vexNum = 0;
}

void createGraph(Graph &g) {
    //cout<<"please input vexNum & edgeNum:"<<endl;
    cin >> g.vexNum;
    //cout<<"please input the head,tail of edge"<<endl;
    for (int i = 0; i < g.vexNum; ++i) {
        for (int j = 0; j < g.vexNum; ++j) {
            cin >> g.edge[i][j];
        }
    }
}

int visited[MAX_VEX] = {0};
int inDegree[MAX_VEX] = {0};

void initDegree(Graph &g) {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < g.vexNum; ++i) {
        for (int j = 0; j < g.vexNum; ++j) {
            if (i != j && g.edge[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
}

bool topoSort(Graph g) {
    stack<int> s;
    int count = 0;
    for (int i = 0; i < g.vexNum; ++i) {
        if (inDegree[i] == 0) {
            s.push(i);
            visited[i] = 1;
        }
    }
    while (!s.empty()) {
        int v = s.top();
        count++;
        s.pop();
        for (int i = 0; i < g.vexNum; ++i) {
            if (v != i && g.edge[v][i] != 0 && !visited[i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    visited[i] = 1;
                    s.push(i);
                }
            }
        }
    }
    if (count == g.vexNum) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    bool arr[100];
    for (int i = 0; i < n; ++i) {
        Graph g;
        initGraph(g);
        createGraph(g);
        initDegree(g);
        arr[i] = topoSort(g);
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }

}


