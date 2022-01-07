//
// Created by Chamb on 2021/12/20.
//
#include "iostream"

using namespace std;

int count = 0;
//用数组表示树，因为是从1开始，所以左右孩子分别是2*i 2*i+1
//以递归的形式,出口是当前结点已经不在树里面
void getChild(int root, int n) {
    if (root > n) {
        return;
    }
    if (root <= n) {
        count++;
    }
    getChild(root * 2, n);
    getChild(root * 2 + 1, n);
}

int main() {
    int input1, input2, m, n;
    int result[100] = {0};
    int res = 0;
    while (1) {
        //先检测一下输入的值是否为0 0
        cin >> input1 >> input2;
        if (input1 == 0 && input2 == 0) {
            break;
        }
        m = input1, n = input2;
        count = 0;
        getChild(m, n);
        result[res] = count;
        res++;
    }
    for (int i = 0; i < res; ++i) {
        cout << result[i] << endl;
    }
}
