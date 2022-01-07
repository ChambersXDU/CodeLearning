//
// Created by Chamb on 2021/12/27.
//
#include "iostream"
using namespace std;
int maxSubString(string s){
    int max = 0;
    for (int i = 1; i <= s.length()-1; ++i) {
        string s1 = s.substr(0,i);
        string s2 = s.substr(s.length()-i);
        if (s1==s2){
            max = i;
        }
    }
    return max;
}

void getNext(string s,int n){
    int arr[100];
    arr[0] = -1;
    arr[1] = 0;
    for (int i = 2; i < n; ++i) {
        arr[i] = maxSubString(s.substr(0,i));
    }
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    char arr[100];
    for (int i = 0; i < n; ++i) {
         cin>>arr[i];
    }
    string s(arr);
    getNext(s,n);
}
