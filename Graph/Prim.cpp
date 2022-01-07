//
// Created by Chamb on 2021/12/19.
//

#include "iostream" //for I/O & test
#include "string.h"//for "memset"

#define MAX_VEX 10
#define INFINITY 10000
using namespace std;
//prim算法的思想：
//一个图的所有边(closeEdge)叫做边集V -> 也就是程序里的c[MAX_VEX]
//建立一个集合U，从一个点出发，把这个点加入U。
//在V-U里面找离U最近的点，并入U。
//不断循环这个过程，直到V-U没有了

//在这里，我们把“ lowCost == 0 ”作为加入U的标志

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
    //在prim里面把自身到自身设置为0
    for (int i = 0; i < MAX_VEX; ++i) {
        g.edge[i][i] = 0;
    }
    g.edgeNum = g.vexNum = 0;
}

void createGraph(Graph &g){
    cout<<"please input vexNum & edgeNum:"<<endl;
    cin>>g.vexNum>>g.edgeNum;
    cout<<"please input the head,tail and lowCost of edge"<<endl;
    for (int i = 1; i <= g.edgeNum; ++i) {
        int head,tail,cost;
        cin>>head>>tail>>cost;
        g.edge[head][tail] = cost;
        g.edge[tail][head] = cost;
    }
}

struct closeEdge{
    int adjVex;//两顶点中在集合U的那个，相当于是一个”前驱“
    int lowCost;//加入到集合U的最小代价
};

void Prim(Graph g, int v){
    closeEdge c[MAX_VEX];
    int minCost = 0;
    //初始化边集
    for (int i = 1; i <= g.vexNum; ++i) {
        c[i].adjVex = v;
        c[i].lowCost = g.edge[v][i];
    }

    //循环vexNum-1次（对于一棵树来说，最多有n-1个连线
    for (int i = 0; i < g.vexNum -1 ; ++i) {
        int nextVex;//要添加的那条边的顶点
        int min = INFINITY;
        //找出V-U中代价最小的点
        for (int j = 1; j <= g.vexNum; ++j) {
            //通过lowCost == 0来判断这个点在不在集合U
            //类似于Dijkstra里面的final或者DFS、BFS里的visited
            //只不过这里没有另开数组来实现
            if (c[j].lowCost != 0 && c[j].lowCost < min){
                min = c[j].lowCost;
                nextVex = j;
            }
        }
        cout<<"("<<c[nextVex].adjVex<<","<<nextVex<<")"<<endl;
        minCost += c[nextVex].lowCost;
        //找出代价最小点之后，V-U发生变化，更新其他点的信息
        //也正是在这里，nextVex的lowCost变为0，正式加入U
        for (int j = 1; j <= g.vexNum; ++j) {
            if (c[j].lowCost != 0 && g.edge[nextVex][j] < c[j].lowCost){
                c[j].adjVex = nextVex;
                c[j].lowCost = g.edge[nextVex][j];
            }
        }
    }
    cout<<"minPath:"<<minCost;
}

int main() {
    Graph g;
    initGraph(g);
    createGraph(g);
    Prim(g,2);
}

