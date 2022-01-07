//
// Created by Chamb on 2021/12/12.
//
#include "iostream"
#include "algorithm"

using namespace std;

int findMaxPos(int arr[], int n) {
    int max = arr[0];
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(int arr[], int n) {
    while (n > 1) {
        int pos = findMaxPos(arr, n);
        swap(arr[pos], arr[n - 1]);
        n--;
    }
}

int main() {
    int arr[6] = {2, 3, 1, 5, 10, 6};
    int n = 6;
    selectionSort(arr, n);
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }
}
