//
// Created by Chamb on 2021/12/26.
//
#include "iostream"
#include "stack"
#include "queue"

using namespace std;

void getString(queue<char> q) {
    char arr[100];
    char front = q.front();
    arr[0] = front;
    q.pop();
    int count = 1;
    while (!q.empty()) {
        arr[count] = q.front();
        count++;
        arr[count] = front;
        count++;
        q.pop();
    }
    for (int i = count - 1; i >= 0; --i) {
        cout << arr[i];
    }
}

int main() {
    string s;
    cin >> s;
    stack<char> stack;
    queue<char> queue;
    int back = s.length() - 1;
    while (back >= 0) {
        stack.push(s[back]);
        back--;
    }
    while (!stack.empty()) {
        char top = stack.top();
        stack.pop();
        if (top == 'B') {
            cout << "tsaedsae";
        } else if (top == '(') {
            //把括号内的字符全进队
            while (stack.top() != ')') {
                char ch = stack.top();
                stack.pop();
                queue.push(ch);
            }
            stack.pop();
            getString(queue);
        } else if (top == 'A') {
            cout << "sae";
        }
    }
}