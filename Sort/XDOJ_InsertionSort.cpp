//
// Created by Chamb on 2021/12/26.
//
#include "iostream"
using namespace std;

void insert(int arr[],int n){
    int i = n;
    int key = arr[n];
    while(i!=0 && arr[i-1]>key){
        arr[i] = arr[i-1];
        i--;
    }
    arr[i] = key;
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 1; i <= 2; ++i) {
        insert(arr,i);
        for (int j = 0; j < n; ++j) {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    insert(arr,3);
    for (int j = 0; j < n; ++j) {
        cout<<arr[j]<<" ";
    }
}
