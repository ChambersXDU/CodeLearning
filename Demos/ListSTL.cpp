//
// Created by Chamb on 2021/12/21.
//
#include "iostream"
#include "list"
using namespace std;

void initList(list<int> *list,int arr[],int n){
    list->assign(arr,arr+n);
}

void traverse(list<int> l){
    for (list<int>::iterator it = l.begin();it!= l.end();it++ ){
        cout<<*it<<" ";
    }
}

void insert(list<int> *l, int n,int position){
    list<int>::iterator it = l->begin();
    advance(it,position-1);
    l->insert(it,n);
}


bool isOdd(int x){
    if (x%2==0){
        return true;
    }
    return false;
}

void removeOdd(list<int> *l){
    l->remove_if(isOdd);
}

int main(){
    list<int>l;
    int arr[5] = {1,2,3,4,5};
    initList(&l,arr,5);
//    insert(&l,6,3);
    removeOdd(&l);
    traverse(l);
}
