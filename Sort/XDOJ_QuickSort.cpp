//
// Created by Chamb on 2021/12/26.
//
#include "iostream"

using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left>=right){
        return;
    }
    int i = left,j = right;
    int pivot = arr[i];
    while (i != j) {
        while (i != j && arr[j] >= pivot) {
            j--;
        }
        arr[i] = arr[j];
        while (i != j && arr[i] <= pivot) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
//    quickSort(arr,left,i-1);
//    quickSort(arr,i+1,right);
}

int main() {
    int n;
    cin >> n;
    int arr[100] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}
