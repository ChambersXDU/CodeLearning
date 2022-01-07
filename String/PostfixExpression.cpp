//
// Created by Chamb on 2021/12/6.
//
#include "iostream"
#include "stack"

using namespace std;

int main() {
    char *num = new char[100];
    cin >> num;
    stack<char> stack;
    int i = 0;
    int opNum1, opNum2, result;
    while (num[i] != '\0') {
        if (num[i] <= '9' && num[i] >= '0')
            //碰到操作数则入栈
            stack.push(num[i]);
        else {
            //碰到操作符则连续两次出栈,将出栈的两个数的运算结果再压入栈
            switch (num[i]) {
                case '+':
                    opNum1 = stack.top() - '0';
                    stack.pop();
                    opNum2 = stack.top() - '0';
                    stack.pop();
                    result = opNum2 + opNum1 + '0';
                    break;
                case '-':
                    opNum1 = stack.top() - '0';
                    stack.pop();
                    opNum2 = stack.top() - '0';
                    stack.pop();
                    result = opNum2 - opNum1 + '0';
                    break;
                case '*':
                    opNum1 = stack.top() - '0';
                    stack.pop();
                    opNum2 = stack.top() - '0';
                    stack.pop();
                    result = opNum2 * opNum1 + '0';
                    break;
                case '/':
                    opNum1 = stack.top() - '0';
                    stack.pop();
                    opNum2 = stack.top() - '0';
                    stack.pop();
                    result = opNum2 / opNum1 + '0';
                    break;
                default:
                    break;
            }
            stack.push(result);
        }
        i++;
    }
    cout << (stack.top() - '0');
}
