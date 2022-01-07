//
// Created by Chamb on 2021/12/6.
//
#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
    int length;
    scanf("%d", &length);
    char *str0 = new char[100];//输入的字符串，是含有空格的
    char str[100] = {0};
    getchar();//gets()会清空缓冲区里的回车符，导致输入length之后直接被跳过
    //使用 gets() 时，系统会将最后“敲”的换行符从缓冲区中取出来，然后丢弃，所以缓冲区中不会遗留换行符。
    // 这就意味着，如果前面使用过 gets()，而后面又要从键盘给字符变量赋值的话就不需要吸收回车清空缓冲区了，因为缓冲区的回车已经被 gets() 取出来扔掉了。
    gets(str0);
    //去除空格
    for (int i = 0, j = 0; i < 2 * length; ++i) {
        if (str0[i] != ' ') {
            str[j] = str0[i];
            j++;
        }
    }
    int next[100] = {0};
    next[0] = -1;
    int i = 1, j = 0;
    while (i < length) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    for (int k = 0; k < length; ++k) {
        cout << next[k] << " ";
    }
}
