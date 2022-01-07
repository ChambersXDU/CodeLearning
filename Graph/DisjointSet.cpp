//
// Created by Chamb on 2021/12/19.
//
#include "iostream"

#define MAXSIZE 100
using namespace std;

int parent[MAXSIZE]={0};
int rank[MAXSIZE] = {0};

void init(int n) {
    for (int i = 0; i < n; ++i) {
        rank[i] = 0;
        parent[i] = -1;
    }
}

int find(int x) {
    int xRoot = x;
    while (parent[xRoot] != -1) {
        xRoot = parent[xRoot];
    }
    return xRoot;
}

int unite(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    //在一个集合，合并失败
    if (xRoot == yRoot) {
        return 0;
    }

    if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else {
        parent[xRoot] = yRoot;
        rank[yRoot]++;
    }
    return 1;
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int edgeNum;
    cin >> edgeNum;
    int edge[MAXSIZE][2];
    for (int i = 0; i < edgeNum; ++i) {
        int head,tail;
        cin>>head>>tail;
        edge[i][0] = head;
        edge[i][1] = tail;
    }
    init(MAXSIZE);
    for (int i = 0; i < edgeNum; ++i) {
        int x = edge[i][0];
        int y = edge[i][1];
        if (unite(x, y) == 0) {
            cout << "cycle detected!";
            exit(0);
        }
    }
    cout << "no cycle found";
    return 0;
}