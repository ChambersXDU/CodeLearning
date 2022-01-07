//
// Created by Chamb on 2021/12/20.
//
#include "iostream"
#include "stdlib.h"
#include "string.h"
using namespace std;

struct tree{
    char data;
    tree *c1;
    tree *c2;
};
typedef tree* BiTree;

int initTree(BiTree &t){
    char ch;
    cin>>ch;
    if (ch == '#'){
        t = NULL;
    } else{
        t = (BiTree)malloc(sizeof (tree));
        t->data = ch;
        initTree(t->c1);
        initTree(t->c2);
    }
    return 0;
}

void midOrder(BiTree t){
    if (t!=NULL){
        midOrder(t->c1);
        cout<<t->data<<" ";
        midOrder(t->c2);
    }
}
int main(){
    BiTree root;
    initTree(root);
    midOrder(root);
}

