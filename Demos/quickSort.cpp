#include <iostream>
#include <stdio.h>
#include <stdlib.h>


typedef struct tree {
    int data;
    struct tree *lc;
    struct tree *rc;
} tree;

void qsort(int low, int high, tree *&t, int a[]) {
    if (low == high) {
        t->data = a[low];
        t->lc = NULL;
        t->rc = NULL;
    } else if (low < high) {
        int key = a[low];
        t = (tree *) malloc(sizeof(tree));
        t->data = key;
        int i = low;
        int j = high;
        while (i < j) {
            while (i < j && a[j] >= key) {
                j--;
            }
            if (i < j) {
                a[i] = a[j];
                i++;
            }
            while (i < j && a[i] <= key) {
                i++;
            }
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = key;
        t->lc = (tree *) malloc(sizeof(t));
        t->rc = (tree *) malloc(sizeof(t));
        int k;
        if (low <= high) {
            qsort(low, i - 1, t->lc, a);
        } else {
            t->lc = NULL;
            t->rc = NULL;
        }


        if (high >= low) {
            qsort(i + 1, high, t->rc, a);
        } else {
            t->rc = NULL;
            t->lc = NULL;
        }
    }

    if (low > high) {
        t = NULL;
    }

}

void late(tree *t) {
    if (t){
        late(t->lc);
        late(t->rc);
        printf("%d ",t->data);
    }
}

int main() {
    int a[100] = {0};
    int n;
    int i, j, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = a[1];
    int low = 1;
    int high = n;
    tree *t;
    qsort(low, high, t, a);
    late(t);
    return 0;
}
