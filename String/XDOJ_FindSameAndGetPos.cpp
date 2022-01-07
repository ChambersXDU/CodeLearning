//
// Created by Chamb on 2021/12/27.
//
#include "iostream"

using namespace std;

bool visited[130] = {false};

bool hasSame(string s, char c) {
    int arr[130];
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            arr[count] = i;
            count++;
        }
    }
    if (count > 1) {
        cout << c << ":" << arr[0];
        for (int i = 1; i < count; ++i) {
            cout << "," << c << ":" << arr[i];
        }
        cout << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (!visited[s[i]] && hasSame(s, s[i])) {
            visited[s[i]] = true;
        }
    }
}
