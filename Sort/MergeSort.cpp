//
// Created by Chamb on 2021/12/12.
//
#include<iostream>

using namespace std;

void merge(int arr[], int L, int M, int R) {
    int LEFT_SIZE = M - L;
    int RIGHT_SIZE = R - M + 1;
    int *left = new int[LEFT_SIZE];
    int *right = new int[RIGHT_SIZE];

    for (int i = L; i < M; ++i) {
        left[i - L] = arr[i];
    }
    for (int i = M; i <= R; ++i) {
        right[i - M] = arr[i];
    }

    int i = 0, j = 0, k = L;
    while (i < LEFT_SIZE && j < RIGHT_SIZE) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < LEFT_SIZE) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < RIGHT_SIZE) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int L, int R) {
    if (L == R) {
        return;
    } else {
        int M = (L + R) / 2;
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);
        merge(arr, L, M + 1, R);
    }
}

int main() {
    int arr[10] = {2, 1, 6, 10, 611, 5, 7, 55, 102, 912};
    int L = 0, R = 9;
    mergeSort(arr, L, R);
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << " ";
    }
}
