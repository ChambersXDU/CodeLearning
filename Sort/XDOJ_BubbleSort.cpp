//
// Created by Chamb on 2021/12/26.
//
#include "iostream"

using namespace std;
int count = 0;

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool hasChanged = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                hasChanged = true;
                count++;
            }
        }
        if (!hasChanged) {
            break;
        }
    }
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bubble(arr, n);
    cout << count;
}
