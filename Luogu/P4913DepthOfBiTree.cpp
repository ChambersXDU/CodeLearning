//
// Created by Chamb on 2022/1/5.
//

#include "iostream"

using namespace std;

struct tree {
    int c1;
    int c2;
};

int ans = 0;

void createTree(tree tree[], int n) {
    for (int i = 0; i <= n; ++i) {
        tree[i].c1 = 0;
        tree[i].c2 = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].c1 >> tree[i].c2;
    }
}

void getDepth(int pos, tree tree[], int depth) {
    if (pos == 0) {
        return;
    } else {
        ans = max(ans, depth);
        getDepth(tree[pos].c1, tree, depth + 1);
        getDepth(tree[pos].c2, tree, depth + 1);
    }
}

int main() {
    tree tree[100];
    int n;
    cin >> n;
    createTree(tree, n);
    getDepth(1, tree, 1);
    cout << ans;
}