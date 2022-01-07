//
// Created by Chamb on 2021/12/12.
//
#include "iostream"

using namespace std;

void heapify(int tree[], int n, int i) {
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    int max = i;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }
    if (max != i) {
        swap(tree[max], tree[i]);
        heapify(tree, n, max);
    }
}

void buildHeap(int tree[], int n) {
    int lastNode = n - 1;
    int parent = (lastNode - 1) / 2;
    for (int i = parent; i >= 0; --i) {
        heapify(tree, n, i);
    }
}

void heapSort(int tree[], int n) {
    buildHeap(tree, n);
    for (int i = n - 1; i >= 0; --i) {
        swap(tree[i], tree[0]);
        heapify(tree, i, 0);
    }
}

int main() {
    int arr[] = {50, 36, 41, 19, 23, 4, 20, 18, 12, 22};
    int n = 10;
    //heapSort(arr,n);
    buildHeap(arr, n);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
};

