//
// Created by Chambers on 2021/11/27.
//
#include "iostream"
#include "algorithm"
#include "stack"
#include "queue"
#include "vector"

using namespace std;

int main() {
    queue<int, vector<int> > q;
    cout << q.empty();
    vector<int> vector;
    vector.push_back(1);
    cout << vector.data();
    return 0;
}
