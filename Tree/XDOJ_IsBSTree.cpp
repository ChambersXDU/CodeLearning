//
// Created by Chamb on 2022/1/1.
//
#include "iostream"

using namespace std;

struct tree{
    int data;
    tree *lChild,*rChild;
};

struct node{
    int data;
    int rPos,lPos;
};

tree *createTree(node arr[],int i){
    if (arr[i].data == 0){
        return NULL;
    } else{
        tree *root = new tree;
        root->data = arr[i].data;
        root->lChild = createTree(arr,arr[i].lPos);
        root->rChild = createTree(arr,arr[i].rPos);
        return root;
    }
}
bool is = true;
void isBST(tree *root){
    if (root!=NULL){
        if (root->lChild != NULL && root->lChild->data > root->data){
            is = false;
        }
        if (root->rChild != NULL && root->rChild->data < root->data){
            is = false;
        }
        isBST(root->lChild);
        isBST(root->rChild);
    }
}

int main(){
    tree *root;
    node nums[100];
    int n,rootPos;
    cin>>n;
    cin>>rootPos;
    nums[0].data = 0;
    nums[0].rPos = 0;
    nums[0].lPos = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>nums[i].data>>nums[i].lPos>>nums[i].rPos;
    }
    root = createTree(nums,rootPos);
    isBST(root);
    if (is){
        cout<<"true";
    } else{
        cout<<"false";
    }
}
