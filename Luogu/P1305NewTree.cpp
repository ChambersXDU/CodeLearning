//
// Created by Chamb on 2021/12/24.
//
#include "iostream"
using namespace std;
struct node{
    char c1,c2;
};
void preOrder(node tree[],char head){
    if (head != '*') {
        cout << head;
        preOrder(tree, tree[head].c1);
        preOrder(tree, tree[head].c2);
    }
}
int main(){
    int n;
    cin>>n;
    node tree[200];
    char head,headC1,headC2;
    cin>>head>>headC1>>headC2;
    tree[head].c1 = headC1;
    tree[head].c2 = headC2;
    for(int i = 1;i<n;i++){
        char no;
        cin>>no;
        cin>>tree[no].c1;
        cin>>tree[no].c2;
    }
    preOrder(tree,head);
}
