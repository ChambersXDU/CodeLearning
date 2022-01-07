//
// Created by Chamb on 2021/12/27.
//
#include "iostream"

using namespace std;

void quickSort(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    if (i >= j) {
        return;
    }
    while (i != j) {
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    arr[low] = arr[i];
    arr[i] = pivot;
//    quickSort(arr,low,i-1);
//    quickSort(arr,i+1,high);
}

int main() {
    int n, arr[100] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}
