//
// Created by Chamb on 2022/1/7.
//
#include "iostream"
#include "vector"
#include "string"
#include "sstream"
#include "algorithm"

using namespace std;

struct node {
    int data;
    int sum;
    node *left;
    node *right;

};

node *build_tree(int *pre, int *mid, int len) {
    int index = 0;
    if (len <= 0)
        return NULL;
    node *root = new node;
    root->data = *pre;
    for (int i = 0; i < len; i++) {
        if (mid[i] == *pre) {
            index = i;
            break;
        }
    }
    root->left = build_tree(pre + 1, mid, index);
    root->right = build_tree(pre + index + 1, mid + index + 1, len - index - 1);
    return root;
}

//递归更新二叉树节点的sum值
void add(node *root) {
    if (root->left == NULL || root->right == NULL) {
        root->sum = 0;
        return;
    }
    add(root->left);
    add(root->right);
    if (root->left != NULL && root->right != NULL) {
        root->sum = root->left->sum + root->left->data + root->right->data + root->right->sum;//左右节点的值加上左右节点的sum值
    }
}

void inorder_display(node *root) {
    if (root != NULL) {
        inorder_display(root->left);
        cout << root->sum << " ";
        inorder_display(root->right);
    }

}

int main() {
    vector<int> vpre, vmid;
    string spre, smid;
    int a = 0;
    while (getline(cin, spre)) {
        getline(cin, smid);
        istringstream is1(spre);
        while (is1 >> a) {
            vpre.push_back(a);
        }
        istringstream is2(smid);
        while (is2 >> a) {
            vmid.push_back(a);
        }

        int *pre = new int[vpre.size()];
        int *mid = new int[vmid.size()];
        for (int i = 0; i < vpre.size(); i++) {
            pre[i] = vpre[i];
            mid[i] = vmid[i];
        }
        //node* root = build_tree(pre,mid,7);
        node *root = build_tree(pre, mid, vpre.size());
        add(root);
        //root->data = root->left->data + root->right->data;
        inorder_display(root);
        cout << endl;
    }
}


