//
// Created by Chamb on 2021/12/21.
//
#include "iostream"
#include "stdio.h"
#include "math.h"

using namespace std;
struct node {
    int key;
    int next;
};
void removeSame(node arr[],int index){
    int key = abs(arr[index].key);
    while (index!=-1){
        int next = arr[index].next;
        if (abs(arr[next].key) == key) {
            int nextNext = arr[next].next;
            arr[index].next = nextNext;
            index = nextNext;
            continue;
        } else{
            index = arr[index].next;
        }
    }
}
int main() {
    node arr[100000];
    int firstNode, num;
    cin >> firstNode >> num;
    for (int i = 0; i < num; ++i) {
        int address;
        cin >> address;
        cin >> arr[address].key;
        cin >> arr[address].next;
    }
    int index = firstNode;

    while (arr[index].next!=-1) {
        removeSame(arr,index);
        printf("%05d %d %05d\n",index,arr[index].key,arr[index].next);
        index = arr[index].next;
    }
    printf("%05d %d -1\n",index,arr[index].key);
}
