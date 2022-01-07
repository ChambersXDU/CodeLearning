//
// Created by Chamb on 2021/12/20.
//
#include "iostream"
#include "algorithm"
#include "string.h"
using namespace std;
int a[30];
int b[30];
void getParent(int x, int y){
    int i = 0,j = 0;
    while (x!=0){
        x = x/2;
        a[i] = x;
        i++;
    }
    while (y!=0){
        y = y/2;
        b[j] = y;
        j++;
    }

    for (int k = 0; k <i ; ++k) {
        for (int l = 0; l < j; ++l) {
            if (a[k] == b[l]){
                cout<<a[k]<<endl;
                return;
            }
        }
    }
}
int main(){
    int x[30] ={0},y[30] = {0};
    int i = 0;
    while(1){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int input1,input2;
        cin>>input1>>input2;
        if (input1 + input2 == 0){
            break;
        }  else{
            x[i] = input1;
            y[i] = input2;
            i++;
        };
    }
    for (int j = 0; j < i; ++j) {
        if (x[j] == 1 || y[j] == 1){
            cout<<1<<endl;
            continue;
        } else{
            getParent(x[j],y[j]);
        }
    }
}
