//
// Created by Chamb on 2021/12/30.
//
#include "iostream"

using namespace std;

struct tree{
    int data;
    tree *lChild,*rChild;
};

int divide(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
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
    return i;
}

tree *quickSort(int arr[], int low, int high) {
    if (low > high) {
        return NULL;
    }
    tree *root = new tree;
    int i = divide(arr, low, high);
    cout<<arr[i]<<" ";
    root->data = arr[i];
    root->lChild = quickSort(arr, low, i - 1);
    root->rChild = quickSort(arr, i + 1, high);
    return root;
}

void midOrder(tree *t){
    if (t){
        midOrder(t->lChild);
        midOrder(t->rChild);
        cout<<t->data<<" ";
    }
}

int main() {
    int arr[100] = {0};
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    tree *root;
    root = quickSort(arr,0,n-1);
    cout<<endl;
    midOrder(root);
}
