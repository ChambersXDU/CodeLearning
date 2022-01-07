//
// Created by Chambers on 2021/11/18.
//
#include "stdio.h"

#define MAXSIZE 100
struct Node {
    int address;
    int key;
    int next;
} node[MAXSIZE];

int main() {
    int add[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i) {
        add[i] = node[i].address;
    }
}
