//
// Created by Chamb on 2021/12/6.
//
//将稀疏矩阵A的非零元以行序为主序的顺序存于一维数组V中，并用二维数组B表示A中的相应元素是否为零元素，例如：
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define MAXLENGTH 10000

int main() {
    int i, j;
    int n, m;
    int p = 0, q = 0, r = 0;    //做加法的下标
    int count1 = 0;        //记录非零元个数
    int count2 = 0;
    int tmp;
    int B1[MAXSIZE][MAXSIZE];
    int B2[MAXSIZE][MAXSIZE];
    int B[MAXSIZE][MAXSIZE] = {0};
    int V1[MAXLENGTH];
    int V2[MAXLENGTH];
    int V[MAXLENGTH] = {0};
    scanf("%d %d", &n, &m);
    //输入矩阵
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &tmp);
            if (tmp == 1)
                count1++;
            B1[i][j] = tmp;
        }
    }
    for (i = 0; i < count1; i++) {
        scanf("%d", &V1[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &tmp);
            if (tmp == 1)
                count2++;
            B2[i][j] = tmp;
        }
    }
    for (i = 0; i < count2; i++) {
        scanf("%d", &V2[i]);
    }
    //做加法
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (B1[i][j] == 1 && B2[i][j] == 0) {
                B[i][j] = 1;
                V[p] = V1[q];
                p++;
                q++;
            } else if (B1[i][j] == 0 && B2[i][j] == 1) {
                B[i][j] = 1;
                V[p] = V2[r];
                p++;
                r++;
            } else if (B1[i][j] == 1 && B2[i][j] == 1) {
                tmp = V1[q] + V2[r];
                q++;
                r++;
                if (tmp != 0) {
                    B[i][j] = 1;
                    V[p] = tmp;
                    p++;

                }
            }
        }
    }
    //输出
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    i = 0;
    while (1) {
        if (V[i] == 0)
            break;
        printf("%d ", V[i]);
        i++;
    }
    return 0;
}