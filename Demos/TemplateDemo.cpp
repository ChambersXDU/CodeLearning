//
// Created by Chambers on 2021/11/27.
//
#include "iostream"
using namespace std;
template <class T>
T myMax(T a,T b){
    if (a>=b){
        return a;
    } else return b;
}

int main(){
    double a = 1.0,b =0.2;
    int c = 2,d= 3;
    cout<<myMax(a,b)<<endl;
    cout<<myMax(c,d);
}
