//
// Created by Chamb on 2021/12/29.
//
#include "iostream"

using namespace std;

struct tree {
    int data, sum;
    tree *lChild, *rChild;
};

int getSum(tree *t) {
    return t->lChild->sum + t->lChild->data +
           t->rChild->sum + t->rChild->data;
}

void getSumTree(tree *t) {
    if (t == NULL) {
        return;
    }
    if (t->lChild == NULL || t->rChild == NULL) {
        t->sum = 0;
        return;
    }
    //类似一种后序
    getSumTree(t->lChild);
    getSumTree(t->rChild);
    if (t->lChild != NULL && t->rChild != NULL) {
        t->sum = getSum(t);
    }
}

tree *createTree(int pre[], int mid[], int len) {
    if (len <= 0) {
        return NULL;
    }
    //新建一个结点
    tree *root = new tree;
    root->data = *(pre);
    root->sum = 0;
    //找到根的位置
    int rootPos = 0;
    while (mid[rootPos] != *(pre)) {
        rootPos++;
    }
    //后序地递归建树
    root->lChild = createTree(pre + 1, mid, rootPos);
    root->rChild = createTree(pre + rootPos + 1, mid + rootPos + 1, len - rootPos - 1);
    return root;
}

void midOrder(tree *t) {
    if (t) {
        midOrder(t->lChild);
        cout << t->sum << " ";
        midOrder(t->rChild);
    }
}

int main() {
    int n, pre[100], mid[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> mid[i];
    }
    tree *root = createTree(pre, mid, n);
    getSumTree(root);
    midOrder(root);
}