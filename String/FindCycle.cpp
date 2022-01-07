//
// Created by Chambers on 2021/11/27.
//
#include "iostream"
#include "cstring"
//#include "algorithm"

using namespace std;

int main() {
    char *ch = new char[1000];
    cin >> ch;
    int length = strlen(ch);
    bool isCycle = false;
    int t;
    for (t = 1; t < length; ++t) {
        if (length % t == 0) {
            isCycle = true;
        }
        for (int i = 0; i < length - t; ++i) {
            if (*(ch + i + t) != *(ch + i)) {
                isCycle = false;
            }
        }
        if (isCycle) {
            break;
        }
    }
    cout << t << endl;
}
