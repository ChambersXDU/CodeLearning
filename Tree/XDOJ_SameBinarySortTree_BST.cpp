//
// Created by Chamb on 2021/12/24.
//
#include "iostream"
#include "string.h"

using namespace std;

void insert(int arr[], int i, int data) {
    if (arr[i] == 0) {
        arr[i] = data;
    }
    if (data < arr[i]) {
        insert(arr, 2 * i + 1, data);
    } else if (data > arr[i]) {
        insert(arr, 2 * i + 2, data);
    }
}

bool isSame(int a[], int b[], int n) {
    bool is = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            is = false;
            break;
        }
    }
    return is;
}

int main() {
    int xx;
    cin>>xx;
    int arr[100] = {0};
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int data;
        data = s.at(i) - '0';
        insert(arr, 0, data);
    }

    while (1) {
        string str;
        cin >> str;
        int a[100] = {0};
        if (str == "0") {
            break;
        }
        for (int i = 0; i < str.length(); ++i) {
            int data;
            data = str[i] - '0';
            insert(a, 0, data);
        }
        if (isSame(a,arr,100)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
}