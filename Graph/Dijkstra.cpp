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

void createGraph(Graph &g){
    cout<<"please input vexNum & edgeNum:"<<endl;
    cin>>g.vexNum>>g.edgeNum;
    cout<<"please input the head,tail and lowCost of edge"<<endl;
    for (int i = 0; i < g.edgeNum; ++i) {
        int head,tail,cost;
        cin>>head>>tail>>cost;
        g.edge[head][tail] = cost;
        g.edge[tail][head] = cost;
    }
}
//Dijkstra
bool final[MAX_VEX]; //记录每个顶点是否已经完成遍历(默认都是false)
int dist[MAX_VEX]; //当前顶点到起点的最短路长（没有路径就是INFINITY)
int path[MAX_VEX]; //路径最小时，当前顶点的前驱(没有就是-1）
void Dijkstra(Graph g, int v) {
    //这个函数用来填好上述的三个数组

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
            if (!final[j] && (dist[minVex] + g.edge[minVex][j]) < dist[j]) {
                dist[j] = dist[minVex] + g.edge[minVex][j];
                path[j] = minVex;
            }
        }
    }
}

void getMinPath(Graph g, int v){
    if (path[v] == -1){
        return;
    }
    getMinPath(g,path[v]);
    cout<< path[v] << "->";
}

void getPathbyDijsktra(Graph g){
    int start,end;
    cout<<"please input the start and end vex:"<<endl;
    cin>>start>>end;
    Dijkstra(g,start);
    cout<<"closest path:";
    getMinPath(g,end);
    cout<<end<<endl;
    cout<< "length:" <<dist[end];
}

int main() {
    Graph g;
    initGraph(g);
    createGraph(g);
    getPathbyDijsktra(g);
}

