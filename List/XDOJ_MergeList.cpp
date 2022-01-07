//
// Created by Chambers on 2021/11/27.
//
/*
 * 已知两个有序线性表L1和L2，每个线性表中数据元素的值为单调增的正整数（<100个），各线性表内部无重复元素。
 * 把L2中的元素合并到L1中，要求L1中数据元素的值仍为单调递增，且无重复元素。
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} *List, node;

void createList(List *head, int n) {
    //param "n" is the length of List "head"
    *head = (List) malloc(sizeof(list));
    (*head)->next = NULL;
    List p;
    for (int i = 0; i < n; ++i) {
        p = (List) malloc(sizeof(list));
        scanf("%d", &p->data);
        p->next = (*head)->next;
        (*head)->next = p;
    }
}

List merge(List L1, List L2) {
    //"head" is the list to record results,and "node" is the node of "head"
    List p1, p2, node, head;
    head = (List) malloc(sizeof(List));
    head->next = NULL;
    //p1,p2 is the pointer to L1 and L2
    //And they will visit every node of L1 & L2
    p1 = L1->next;
    p2 = L2->next;
    while ((p1 != NULL) && (p2 != NULL)) {
        if (p1->data > p2->data) {
            node = (List) malloc(sizeof(node));
            node->data = p1->data;
            node->next = head->next;
            head->next = node;
            p1 = p1->next;
        } else if (p1->data < p2->data) {
            node = (List) malloc(sizeof(node));
            node->data = p2->data;
            node->next = head->next;
            head->next = node;
            p2 = p2->next;
        } else {
            node = (List) malloc(sizeof(node));
            node->data = p1->data;
            node->next = head->next;
            head->next = node;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        node = (List) malloc(sizeof(node));
        node->data = p1->data;
        node->next = head->next;
        head->next = node;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        node = (List) malloc(sizeof(node));
        node->data = p2->data;
        node->next = head->next;
        head->next = node;
        p2 = p2->next;
    }
    return head;
}

void Print(List head) {
    List p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n1, n2;
    List L1, L2, L3;
    scanf("%d %d", &n1, &n2);
    createList(&L1, n1);
    createList(&L2, n2);
    L3 = merge(L1, L2);
    Print(L3);
    return 0;
}
