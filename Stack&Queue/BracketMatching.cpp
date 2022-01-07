//
// Created by Chamb on 2021/12/6.
//
#include "iostream"
#include "stack"

using namespace std;

int main() {
    char *str = new char[100];
    gets(str);
    stack<char> stack;
    int i = 0;
    while (str[i] != '\0') {
        i++;
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
            stack.push(str[i]);
        } else if (str[i] == ')') {
            if (!stack.empty() && stack.top() != '(') {//首先栈不能为空 && 栈顶元素不匹配，输出wrong
                cout << "wrong";
                return 0;
            } else {//匹配上了
                stack.pop();
            }
        } else if (str[i] == ']') {
            if (!stack.empty() && stack.top() != '[') {
                cout << "wrong";
                return 0;
            } else {
                stack.pop();
            }
        } else if (str[i] == '}') {
            if (!stack.empty() && stack.top() != '{') {
                cout << "wrong";
                return 0;
            } else {
                stack.pop();
            }
        }

    }
    if (!stack.empty()) {
        cout << "wrong";
        return 0;
    }
    cout << "right";
}