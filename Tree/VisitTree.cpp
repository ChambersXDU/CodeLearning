//
// Created by Chamb on 2021/12/17.
//
#include "iostream"
#include "queue"
#include "cstring"

using namespace std;
struct tree {
    int data;
    tree *lChild;
    tree *rChild;
};

void preOrder(tree *t) {
    if (t) {
        cout << t->data << " ";
        preOrder(t->lChild);
        preOrder(t->rChild);
    }
}

void levelOrder(tree *T) {
    queue<tree *> q;
    tree *p = T;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        cout << p->data << " ";
        q.pop();
        if (p->lChild) {
            q.push(p->lChild);
        }
        if (p->rChild) {
            q.push(p->rChild);
        }
    }
}

int getHeight(tree *t) {
    int lHeight, rHeight;
    if (t == NULL) {
        return 0;
    } else {
        lHeight = getHeight(t->lChild);
        rHeight = getHeight(t->rChild);
        if (lHeight > rHeight) {
            return lHeight + 1;
        } else {
            return rHeight + 1;
        }
    }
}

int leafCount(tree *t){
    if (t == NULL){
        return 0;
    }
    if (!t->rChild && !t->lChild){
        cout<< " "<<t->data;
        return 1;
    }
    return leafCount(t->lChild)+ leafCount(t->rChild);

}

int nodeCount(tree *t){
    if (t == NULL){
        return 0;
    }

    return nodeCount(t->rChild)+ nodeCount(t->lChild) + 1;

}

int main() {
    tree t1, t2, t3, t4;

    t1.data = 1, t2.data = 2, t3.data = 3, t4.data = 4;
    t1.lChild = &t2;
    t1.rChild = &t3;

    t2.lChild = &t4, t2.rChild = NULL;
    t3.rChild = t3.lChild = NULL;
    t4.rChild = t4.lChild = NULL;

    preOrder(&t1);
    levelOrder(&t1);
    cout <<"\nheight:"<< getHeight(&t1)<<endl;
    cout<<"\nleaf:  "<< leafCount(&t1);
    cout<<"\nnode:  "<< nodeCount(&t1);
}

