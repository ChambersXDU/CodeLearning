//
// Created by Chambers on 2021/11/16.
//
#include "stdio.h"
#include "malloc.h"
#include "iostream"

using namespace std;

typedef struct tree {
    int data;
    struct tree *rChild;
    struct tree *lChild;
} tree;

tree *creatTree(int a[], int i) {
    if (a[i]) {
        tree *p = new tree;
        p->data = a[i];
        p->lChild = creatTree(a, 2 * i);
        p->rChild = creatTree(a, 2 * i + 1);
        return p;
    } else {
        return NULL;
    }
}

void mid(tree *t) {
    if (t) {
        mid(t->lChild);
        printf("%d ", t->data);
        mid(t->rChild);
    }
}

void pre(tree *t) {
    if (t) {
        cout << t->data << " ";
        pre(t->lChild);
        pre(t->rChild);
    }
}

void post(tree *t) {
    if (t) {
        post(t->lChild);
        post(t->rChild);
        printf("%d ", t->data);
    }
}

int main() {
    int a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    tree *root = creatTree(a, 1);
    pre(root);
    printf("\n");
    mid(root);
    printf("\n");
    post(root);
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             佛祖保佑       永无BUG
*/