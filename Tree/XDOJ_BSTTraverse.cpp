//
// Created by Chamb on 2021/12/24.
//
#include "iostream"

using namespace std;

void insert(int arr[], int i, int data) {
    if (arr[i] == 0) {
        arr[i] = data;
    }
    if (data < arr[i]) {
        insert(arr, 2 * i + 1, data);
    } else if (data > arr[i]) {
        insert(arr, 2 * i + 2, data);
    } else {}//相等，不处理
}

void preOrder(int arr[], int i) {
    if (arr[i] != 0) {
        cout << arr[i] << " ";
        preOrder(arr, 2 * i + 1);
        preOrder(arr, 2 * i + 2);
    }
}

void midOrder(int arr[], int i) {
    if (arr[i] != 0) {
        midOrder(arr, 2 * i + 1);
        cout << arr[i] << " ";
        midOrder(arr, 2 * i + 2);
    }
}

void postOrder(int arr[], int i) {
    if (arr[i] != 0) {
        postOrder(arr, 2 * i + 1);
        postOrder(arr, 2 * i + 2);
        cout << arr[i] << " ";
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
    preOrder(arr, 0);
    cout << endl;
    midOrder(arr, 0);
    cout << endl;
    postOrder(arr, 0);
    cout << endl;
}