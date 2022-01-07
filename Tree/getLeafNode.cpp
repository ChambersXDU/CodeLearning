//
// Created by Chamb on 2021/12/17.
//
/*
 * 问题描述：
建立二叉链表，统计二叉树中的叶子结点数并输出。
输入说明：
按照完全二叉树的形式输入二叉树的各结点数据(字符)，其中虚结点用’@‘表示。输入以’#'结束。
输出说明：
输出叶子结点的个数及具体值。第一行为叶子结点的数据值，各数据用空格分隔，第二行为叶子结点的个数。
输入样例：
abc@@de#
输出样例：
b d e
3
 */

#include <cstdlib>
#include "iostream"
using namespace std;

struct tree{
    char data;
    tree *c1;
    tree *c2;
};
void preOrder(tree *t) {
    if (t) {
        cout << t->data << " ";
        preOrder(t->c1);
        preOrder(t->c2);
    }
}

tree *initTree(char *arr,int i){
    if (arr[i]){
        tree *t = (tree *) malloc(sizeof(tree));
        t->data = arr[i];
        t->c1 = initTree(arr,2*i);
        t->c2 = initTree(arr,i*2+1);
        return t;
    } else{
        return NULL;
    }
}

int main(){
    tree *t;
    char arr[10] = "0abc@@de#";
    t = initTree(arr,1);
    preOrder(t);
};