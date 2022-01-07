//
// Created by Chamb on 2021/12/20.
//
#include "iostream"
#include "math.h"
using namespace std;
void print(int arr[],int n,int d){
    int start = pow(2,d-1);
    int end = 2*start;
    if (end>n){
        end = n;
    }
    for (int i = start; i < end; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
//    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//    print(arr,2);
//
    while(1){
        int tree[100];
        int n,d;
        cin>>n;
        if (n == 0){
            break;
        }
        for (int i = 1; i <= n; ++i) {
            cin>>tree[i];
        }
        cin>>d;
        print(tree,n,d);
    }
}
