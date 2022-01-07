//
// Created by Chamb on 2021/12/6.
//
#include "iostream"
#include "stack"

using namespace std;

int main() {
    int n;
    int num[20] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int key;
    for (int i = 0; i < n; ++i) {
        key = num[i];
        for (int j = i + 1; j < n; ++j) {

            if (num[i] > num[j]) {
                //num[i]后面出现更小的几个数，则看它们是否是“逆序”的（如3后面有 2 、1，则21是逆序）
                //每次有更小的值就更新一次key值
                if (num[j] <= key) {
                    key = num[j];
                } else {
                    cout << "no";
                    return 0;
                }
            }
        }
    }
    cout << "yes";
    return 0;
}

