//
// Created by Chamb on 2021/12/19.
//

#include "iostream" //for I/O & test
#include "string.h"//for "memset"
#include "vector"
#include "algorithm"

#define MAX_VEX 10
#define INFINITY 10000
using namespace std;
//图的表示
struct Graph {
    int vexNum, edgeNum;
    int vex[MAX_VEX];
    int edge[MAX_VEX][MAX_VEX];
};

struct Edge{
    int from;
    int to;
    int weight;
};

vector<Edge>l;

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
        l[i].from = head;
        l[i].to = tail;
        l[i].weight =cost;
    }
}

//Kruscal
bool cmp(Edge e1,Edge e2){
    if (e1.weight<e2.weight){
        return true;
    } else{
        return false;
    }
}
void Kruscal(Graph g){
    sort(l.begin(),l.end(),cmp);
    int vexSet[MAX_VEX];
    int minCost = 0;
    for (int i = 0; i < g.vexNum; ++i) {
        vexSet[i] = i;
    }

    int all = 0;
    for (int i = 0; i < g.edgeNum; ++i) {
        if (all == g.vexNum -1){
            break;
        }
        int v1 = vexSet[l[i].from];
        int v2 = vexSet[l[i].to];
        if (v1!=v2){
            cout<<l[i].from<<" "<<l[i].to<<" "<<l[i].weight<<endl;
            minCost += l[i].weight;
            for (int j = 0; j < g.vexNum; ++j) {
                if (vexSet[j] == v2){
                    vexSet[j] = v1;
                }
            }
            all ++;
        }
    }
}

int main() {
    Graph g;
    initGraph(g);
    createGraph(g);
    Kruscal(g);
}


