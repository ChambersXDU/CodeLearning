//
// Created by Chamb on 2021/12/21.
//
#include "iostream"
#include "vector"

using namespace std;



void eraseNum(vector<int>&v,int count){
    for (int j = 0; j < v.size(); ++j) {
        if ((j + 1) % count == 0) {
            v[j] = -1;
        }
    }
    for (int k = 0; k < v.size(); ++k) {
        if (v[k] == -1) {
            v.erase(v.begin() + k);
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;//不能像数组一样直接赋值，因为还没有开辟空间，除非初始化的时候就制订了长度
    }

    while (v.size()>3){
        if (v.size()>3){
            eraseNum(v,2);
        } else {
            break;
        }
        if (v.size()>3){
            eraseNum(v,3);
        } else{
            break;
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i]+1<<" ";
    }
}