//
// Created by Chamb on 2021/12/12.
//
#include <iostream>

using namespace std;

void insert(int arr[], int n) {
    int i = n;
    int key = arr[n];
    while (i != 0 && arr[i - 1] > key) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = key;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        insert(arr, i);
    }
}

int main() {
    int arr[6] = {2, 3, 1, 5, 10, 0};
    insertionSort(arr, 6);
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }
}
