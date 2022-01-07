//
// Created by Chamb on 2021/12/30.
//
#include "iostream"

using namespace std;
#define MAX_VEX 100
#define INFINITY 10000
struct Graph {
    int edge[MAX_VEX][MAX_VEX];
    int n;
};

void Floyd(Graph *g, int D[MAX_VEX][MAX_VEX], int path[MAX_VEX][MAX_VEX]) {
    int i, j, k;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            D[i][j] = g->edge[i][j];
            if (g->edge[i][j] < INFINITY)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
    }
    for (k = 0; k < g->n; k++) {
        for (i = 0; i < g->n; i++) {
            for (j = 0; j < g->n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

int main() {
    int i, j, k;
    int D[100][100], path[100][100];
    Graph *g = new Graph;
    scanf("%d", &g->n);
    for (i = 0; i < g->n; i++){
        for (j = 0; j < g->n; j++){
            cin>>g->edge[i][j];
        }
    }
    Floyd(g, D, path);
    int start, end;
    while (scanf("%d %d", &start, &end) && (start + end != -2)) {
        k = path[start][end];
        if (k == -1) {
            cout<<"NO"<<endl;
            continue;
        }
        cout << D[start][end] << endl;
        cout << start<<" ";
        //Get path
        while (k != end) {
            cout<<k<<" ";
            k = path[k][end];
        }
        cout << end << endl;
    }
    return 0;
}

