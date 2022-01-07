//
// Created by Chamb on 2021/12/19.
//
#include "iostream" //for I/O & test
#include "algorithm"
#include "string.h"//for "memset"
#include "queue" //for BFS

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
    cout << "input vexNum and edgeNum";
    int vexNum, edgeNum;
    cin >> vexNum>>edgeNum;
    g.vexNum = vexNum;
    g.edgeNum = edgeNum;
    cout << "please input the head,tail" << endl;
    for (int i = 0; i < g.edgeNum; ++i) {
        int head, tail;
        cin >> head >> tail;
        g.edge[head][tail] = 1;
        g.edge[tail][head] = 1;
    }
}

//基本操作
int visited[MAX_VEX] = {0};

//BFS
void BFS(Graph &g, int v) {
    //make a visit
    cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i] && g.edge[v][i]) {
            //if i is the neighboring vex of start
            //and i has never been visited
            //than BFS from i
            BFS(g, i);
        }
    }
}
void DFSTraverse(Graph g) {
    for (int i = 0; i < MAX_VEX; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i])
            BFS(g, i);
    }
}
//BFS
void BFS(Graph &g, int v) {
    //BFS needs a queue for help
    queue<int> queue;
    cout << g.vex[v];
    visited[v] = 1;
    queue.push(v);
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (int i = 0; i < g.vexNum; ++i) {
            if (!visited[i] && g.edge[v][i]) {
                cout << i;
                visited[i] = 1;
                queue.push(i);
            }
        }
    }
}

//BFS Traverse
void BFSTraverse(Graph g) {
    for (int i = 0; i < MAX_VEX; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < g.vexNum; ++i) {
        if (!visited[i]) {
            BFS(g, i);
        }
    }
}

//Dijkstra

bool final[MAX_VEX]; //记录每个顶点是否已经完成遍历(默认都是false)
int dist[MAX_VEX]; //当前顶点到起点的最短路长（没有路径就是INFINITY)
int path[MAX_VEX]; //路径最小时，当前顶点的前驱(没有就是-1）
void Dijkstra(Graph g, int v) {

    //初始化三个数组
    for (int i = 0; i < g.vexNum; ++i) {

        final[i] = false;
        dist[i] = g.edge[v][i];
        if (dist[i] < INFINITY) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    final[v] = true;
    dist[v] = 0;

    for (int i = 0; i < g.vexNum; ++i) {
        //首先，找到一个离起点最近的顶点
        int min = INFINITY;//这一趟的最小路径
        int minVex;//记录这一趟的最小路径点
        for (int j = 0; j < g.vexNum; ++j) {
            if (!final[j] && dist[j] < min) {
                min = dist[j];
                minVex = j;//可能是最小路径点，但还需要遍历完整个图
            }
        }
        final[minVex] = true;
        //从这个最近点出发，更新其他结点到起点v的最短距离dist
        for (int j = 0; j < g.vexNum; ++j) {
            //当v->minVex->i要比v->i更近时，更新它的dist,并以minVex当做它的前驱
            if (!final[j] && (dist[minVex] + g.edge[v][j]) < dist[j]) {
                dist[j] = dist[minVex] + g.edge[v][j];
                path[j] = minVex;
            }
        }
    }
}
//Floyd


int main() {
    Graph g;
    initGraph(g);
    createGraph(g);
    DFSTraverse(g);
}
