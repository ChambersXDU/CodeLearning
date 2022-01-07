//
// Created by Chamb on 2021/12/26.
//
#include "iostream"

using namespace std;
int c[100] = {0};
int k = 0;
void merge(int a[], int b[], int m, int n) {
    int i = 0, j = 0;
    while (i<m && j<n){
        if (a[i]<b[j]) {
            c[k] = a[i];
            i++;
            k++;
        } else if (a[i] == b[j]){
            c[k] = a[i];k++;
            c[k] = b[j];k++;
            i++;
            j++;
        } else{
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i!=m){
        c[k] = a[i];
        k++;
        i++;
    }
    while (j!=n){
        c[k] = b[j];
        k++;
        j++;
    }
}

int main() {
    int m,n;
    int a[100],b[100];
    cin>>m>>n;
    for (int i = 0; i < m; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    merge(a,b,m,n);
    for (int i = 0; i < k; ++i) {
        cout<<c[i]<<" ";
    }
}
