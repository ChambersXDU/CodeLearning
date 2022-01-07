//
// Created by Chamb on 2021/12/26.
//
#include "iostream"

using namespace std;

void heapify(int arr[], int n, int i) {
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int min = i;
    if (c1 < n && arr[c1] < arr[min]) {
        min = c1;
    }
    if (c2 < n && arr[c2] < arr[min]) {
        min = c2;
    }
    if (min != i) {
        swap(arr[min], arr[i]);
        heapify(arr, n, min);
    }
}

void buildHeap(int arr[],int n){
    int lastNode = n-1;
    int parent = (lastNode-1)/2;
    for (int i = parent; i >= 0; --i) {
        heapify(arr,n,i);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    buildHeap(arr,n);
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
}
