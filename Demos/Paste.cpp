//
// Created by Chambers on 2021/11/27.
//

#include<stdio.h>
#include<queue>
#include<functional>

using namespace std;
priority_queue<int, vector<int>, greater<int> > q;//最小堆 第三个参数 less<int> 最大堆

int main() {
    int n, wpl = 0, i, t[1000];
    int a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        q.push(t[i]);
    }
    while (q.size() >= 2) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        wpl = wpl + a + b;
    }
    printf("%d", wpl);
}
