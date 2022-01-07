//
// Created by Chamb on 2021/12/30.
//
#include "iostream"

#define MAX_VEX 100
#define INFINITY 10000
using namespace std;

struct Graph {
    int vexNum;
    int edge[MAX_VEX][MAX_VEX];
};

int D[MAX_VEX][MAX_VEX];
int path[MAX_VEX][MAX_VEX];

void Floyd(Graph g) {
    for (int i = 0; i < g.vexNum; ++i) {
        for (int j = 0; j < g.vexNum; ++j) {
            D[i][j] = g.edge[i][j];
            if (g.edge[i][j] < INFINITY){
                path[i][j] = j;
            } else{
                path[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < g.vexNum; ++i) {
        for (int j = 0; j < g.vexNum; ++j) {
            for (int k = 0; k < g.vexNum; ++k) {
                if (D[j][i] + D[i][k] < D[j][k]) {
                    D[j][k] = D[j][i] + D[i][k];
                    path[j][k] = path[j][i];
                }
            }
        }
    }
}

void getPath(int end, int start) {
    if (path[start][end] == -1) {
        cout<<"NO";
        return;
    }
    cout<<D[start][end]<<endl;
    cout << start<<" ";
    int k = path[start][end];
    while (k != end) {
        cout << k<<" ";
        k = path[k][end];
    }
    cout<< end;
}

void initGraph(Graph &g, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g.edge[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    Graph g = {};
    g.vexNum = n;
    initGraph(g, n);
    Floyd(g);
    while (true) {
        int input1, input2;
        cin >> input1 >> input2;
        if (input2 + input1 < 0) {
            break;
        }
        getPath(input2, input1);
        cout<<endl;
    }
    //return 0;
}
