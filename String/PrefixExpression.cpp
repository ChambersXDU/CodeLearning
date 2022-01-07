//
// Created by Chamb on 2021/12/7.
//
#include "iostream"
#include "cstring"

using namespace std;

int main() {
    char *str = new char[100];
    int stack[100] = {0};
    int top = -1;

    int num[100] = {0};//用来存字符串里数字的
    int index = 0;//num的下标
    //gets(str);
    cin.get(str, 100);
    int len = strlen(str);
    //和后缀表达式题目里不同的是，这里的输入含有空格、数字可能是多位，
    // 因此要先将数字进行处理使其变成“整个”的元素。
    for (int i = 0; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int numElement = 0;
            while (str[i] != ' ' && str[i] != '\0') {
                //比如“16 9 +” ，遇到空格说明整个数已经被读完
                numElement = numElement * 10 + str[i] - '0';
                i++;
            }
            num[index] = numElement;
            index++;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        //逆序读取str
        if (str[i] >= '0' && str[i] <= '9') {
            //读取到数字，把num里面的元素提取出来
            //对于“+ * + 42 8 – 36 6 / 9 3”这里的36
            //+ * + 42 8 – 36 6 / 9 3
            //+ * + 42 8 - 36 6 / 9 3
            //逆序读取的时候，先读到6，那么就可以直接去num里面把36取出来
            //至于‘3’，可以直接跳过，直到读到‘ ’为止
            top++;
            index--;
            stack[top] = num[index];
            while (str[i] != ' ') {
                i--;
            }
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int opNum1 = stack[top];
            top--;
            int opNum2 = stack[top];
            top--;

            if (str[i] == '+') {
                top++;
                stack[top] = opNum1 + opNum2;
            }

            if (str[i] == '-') {
                top++;
                stack[top] = opNum1 - opNum2;
            }

            if (str[i] == '*') {
                top++;
                stack[top] = opNum1 * opNum2;
            }

            if (str[i] == '/') {
                top++;
                stack[top] = opNum1 / opNum2;
            }
        }
    }
    cout << stack[top];
    return 0;
}
