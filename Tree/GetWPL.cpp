//
// Created by Chambers on 2021/11/27.
//
#include<iostream>
#include<queue>
#include<functional>

using namespace std;
//最小堆 第三个参数 less<int> 最大堆
//优先队列，利用greater<int>定义一个“优先级”,greater是小顶堆
//实际上，WPL = Σ非叶子结点
int getWPL(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int> > q(arr, arr + n);
    int a, b, wpl = 0;
    while (q.size() >= 2) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        wpl += a + b;
    }
    return wpl;
}

int main() {
//    int n, wpl = 0, i, t[1000];
//    int a, b;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &t[i]);
//        q.push(t[i]);
//    }
//    while (q.size() >= 2) {
//        a = q.top();
//        q.pop();
//        b = q.top();
//        q.pop();
//        q.push(a + b);
//        wpl = wpl + a + b;
//    }
//    printf("%d", wpl);
    int n;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<getWPL(arr,n);
}

