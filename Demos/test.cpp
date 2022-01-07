#include "iostream"
#include "stack"
using namespace std;
struct list {
    int data;
    struct list *next;
} *List, node;

int main() {
    stack<int>stack;
    cout<<stack.empty();
}