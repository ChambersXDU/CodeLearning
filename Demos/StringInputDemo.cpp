//
// Created by Chamb on 2022/1/5.
//
#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    char c1[100],c2[100];
    for (int i = 0; i < n; ++i) {
        cin>>c1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>c2[i];
    }
    string pre(c1),mid(c2);
    cout<<pre;
}
