//
// Created by Chamb on 2021/12/30.
//
#include "iostream"
using namespace std;
struct tree{
    int data;
    tree *c1,*c2;
};

tree* createTree(int arr[],int i){
    if(arr[i] == 0){
        return NULL;
    } else{
        tree *root = new tree;
        root->data = arr[i];
        root->c1 = createTree(arr,2*i+1);
        root->c2 = createTree(arr,2*i+2);
        return root;
    }
}

void preOrder(tree *root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->c1);
        preOrder(root->c2);
    }
}

int main(){
    int arr[100] = {0};
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    tree *root;
    root = createTree(arr,0);
    preOrder(root);
}