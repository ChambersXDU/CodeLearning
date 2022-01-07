//
// Created by Chamb on 2021/12/26.
//
#include "iostream"
using namespace std;
void shellSort(int arr[],int n){
    int increment = n/2;
    int temp;
    for (int i = increment; i < n; ++i) {
        int j;
        temp = arr[i];
        //这里类似插入排序，只不过是间隔了increment
        //先把arr[i]存起来，把前面比它大往后转移，移动完成就把temp里存的填进空位
        for (j = i-increment; j >=0 ; j = j-increment) {
            if (arr[j]>temp){
                arr[j+increment] = arr[j];
            } else{
                break;
            }
        }
        arr[j+increment] = temp;
    }
}

int main(){
    int n,arr[100];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    shellSort(arr,n);
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
}
