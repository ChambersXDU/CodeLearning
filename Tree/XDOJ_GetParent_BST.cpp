//
// Created by Chamb on 2021/12/24.
//
#include "iostream"

using namespace std;

void insert(int arr[], int i, int data) {
    if (arr[i] == 0) {
        arr[i] = data;
        if (i == 0) {
            cout << -1 << endl;
        } else {
            cout << arr[(i - 1) / 2] << endl;
        }
    }
    if (data > arr[i]) {
        insert(arr, 2 * i + 1, data);
    }
    if (data < arr[i]) {
        insert(arr, 2 * i + 2, data);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[1000] = {0};
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insert(arr, 0, data);
    }
}
