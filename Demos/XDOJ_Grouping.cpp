//
// Created by Chamb on 2022/1/1.
//
#include "iostream"

using namespace std;
int visited[100] = {0};
int visitedNum[100] = {0};
int G[100][100];

void initG() {
    for (int i = 0; i < 100; ++i) {
        visited[i] = 0;
        for (int j = 0; j < 100; ++j) {
            visitedNum[j] = 0;
            G[i][j] = 0;
        }
    }
}

void grouping(int num[], int group[], int n) {
    for (int i = 0; i < n; ++i) {
        int g = group[i];
        int n = num[i];
        G[g][n]++;
        visited[g] = 1;
        visitedNum[n] = 1;
    }
}

bool isLast(int i) {
    bool isLast = true;
    if (visitedNum[i] == 1 || i == 99) {
        int j = i + 1;
        while (j <= 99) {
            if (visitedNum[j] == 1) {
                isLast = false;
            }
            j++;
        }
    }
    return isLast;
}

void printGroup() {
    for (int i = 0; i < 100; ++i) {
        if (visited[i]) {
            cout << i << "={";
            for (int j = 0; j < 100; ++j) {
                if (visitedNum[j] != 0) {
                    if (isLast(j)) {
                        cout << j << "=" << G[i][j];
                    } else {
                        cout << j << "=" << G[i][j] << ",";
                    }
                }
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    int num[100], group[100];
    int cycles;
    cin>>cycles;
    for (int i = 0; i < cycles; ++i) {
        initG();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> group[i];
        }
        grouping(num, group, n);
        printGroup();
    }
}
