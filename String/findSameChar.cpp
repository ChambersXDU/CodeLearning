//
// Created by Chamb on 2021/12/21.
//
#include "iostream"
#include "string.h"
#include "stdio.h"

using namespace std;

int main() {
    char str[100];
    gets(str);
    int len = strlen(str);
    int res[200] = {0};
    for (int i = 0; i < len; ++i) {
        res[str[i]]++;
    }
    for (int i = 0; i < 200; ++i) {
        if (res[i] != 0) {
            printf("%c : %d\n", i, res[i]);
        }
    }
}
