//
// Created by Chamb on 2021/12/24.
//
#include "iostream"

using namespace std;

//pre B AGCD ZHKX
//mid ACGD B HZKX
void getPost(string pre, string mid) {
    if (!pre.empty()) {
        char root = pre[0];
        int pos = mid.find(root);
        string leftPre = pre.substr(1, pos);
        string leftMid = mid.substr(0, pos);
        string rightPre = pre.substr(pos + 1);
        string rightMid = mid.substr(pos + 1);
        getPost(leftPre, leftMid);
        getPost(rightPre, rightMid);
        cout << root;
    }
}

int main() {
    string pre, mid;
    cin >> pre >> mid;
    getPost(pre, mid);
}

/*
 *
 * void getPost(int l1,int r1,int l2,int r2) {
    //在中序遍历中范围l1-r1,先序l2-r2
    if (l1>r1){
        return;
    }
    int root = pre[l2];
    int pos = l1;
    while (mid[pos]!=root){
        pos++;
    }
    int left = pos - l1;//中序里面根左边结点个数
    getPost(l1,pos-1,l2+1,l2+left);
    getPost(pos+1,r1,l2+left+1,r2);
    post[count++] = root;
}
 *
 */