//
// Created by Chambers on 2021/11/27.
//
#include<cstdio>

#define MAXSTRLEN 200
using namespace std;

int main() {
    char a[MAXSTRLEN];
    int i, n;
    int key = 1;
    scanf("%d", &n);
    scanf("%s", a);
    for (i = 0; i < (n / 2); i++) {
        if (a[i] != a[n - 1 - i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}