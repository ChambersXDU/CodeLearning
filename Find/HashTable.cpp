//
// Created by Chamb on 2021/12/21.
//
#include "iostream"

using namespace std;

int getPosition(int max, int table[], int key, int n) {
    int p = key % n;
    while (table[p] != 0) {
        p = (p + 1) % max;
    }
    return p;
}
int isInTable(int table[],int key){
    for (int i = 0; i < 101; ++i) {
        if (table[i]==key){
            return i;
        }
    }
    return -1;
}
void hashTable(int max, int n) {
    int table[101] = {0};
    int position;
    int count = 0;
    while (count!=max-1) {
        int input;
        cin >> input;
        if (input == -1){
            return;
        }
        if (isInTable(table,input)>=0){
            cout<<isInTable(table,input)<<endl;
            continue;
        }
        count++;
        position = getPosition(max, table, input, n);
        table[position] = input;
        cout << position << endl;
    }
    cout<<"Table full";
}

int main() {
    int max, n;
    cin >> max >> n;
    hashTable(max,n);
}
