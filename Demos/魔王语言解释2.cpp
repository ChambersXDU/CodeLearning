//
// Created by Chambers on 2021/11/13.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXSIZE 120

typedef struct node {
    char data;
    struct node *link;
} StackNode, QueueNode;

typedef struct {
    StackNode *top;
} LinkStack;

typedef struct {
    QueueNode *rear;
    QueueNode *front;
} LinkQueue;

void InitStack(LinkStack *s) {
    s->top = NULL;
}

void InitQueue(LinkQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int push(LinkStack *s, char x) {
    StackNode *p = (StackNode *) malloc(sizeof(node));
    if (!p) return -1;
    p->data = x;
    p->link = s->top;
    s->top = p;
    return 1;
}

int pop(LinkStack *s, char *x) {
    if (s == NULL || s->top == NULL) {
        return 0;
    }
    StackNode *p = s->top;
    *x = p->data;
    s->top = p->link;
    free(p);
    return 1;
}

int EnQueue(LinkQueue *q, char x) {
    QueueNode *p = (QueueNode *) malloc(sizeof(QueueNode));
    if (!p) {
        return 0;
    }
    p->data = x;
    p->link = NULL;
    if (q->front == NULL) {
        q->rear = p;
        q->front = p;
    } else {
        q->rear->link = p;
    }
    q->rear = p;
    return 1;
}

int DeQueue(LinkQueue *q, char *x) {
    if (q->front == NULL) return 0;
    QueueNode *p = q->front;
    *x = p->data;
    q->front = q->front->link;
    free(p);
    return 1;
}

int main() {
    char data;
    char monster_word[MAXSIZE] = {0};
    LinkStack stack;
    LinkQueue queue;
    InitQueue(&queue);
    InitStack(&stack);

    scanf("%s", &monster_word);

    for (int i = strlen(monster_word) - 1; i >= 0; --i) {
        push(&stack, monster_word[i]);
    }
    while (pop(&stack, &data)) {
        if (data == 'A') {
            printf("sae");
        } else if (data == 'B') {
            printf("tsaedsae");
        } else if (data == '(') {
            char frontData;
            while (data != ')') {
                pop(&stack, &data);
                EnQueue(&queue, data);
            }
            DeQueue(&queue, &data);
            frontData = data;
            while (DeQueue(&queue, &data)) {
                push(&stack, frontData);
                push(&stack, data);
            }
        } else if (data == ')') {}
        else {
            printf("%c", data);
        }
    }
    return 0;
}