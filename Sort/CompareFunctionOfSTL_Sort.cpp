//
// Created by Chamb on 2021/12/26.
//
#include "iostream"
#include "algorithm"

using namespace std;
struct student {
    int age;
    int ID;
};

bool cmp(student s1, student s2) {
    return s1.age > s2.age;
}

int main() {
//    student s1,s2;
//    s1.age = 20;
//    s2.age = 22;
//    student s[2];
//    s[0] = s2;
//    s[1] = s1;
//    sort(s,s+1,cmp);
//    for (int i = 0; i < 2; ++i) {
//        cout<<s[i].age;
//    }

    int arr[5] = {2, 6, 1, 5, 4};
    sort(arr, arr + 5);
    for (int i = 0; i < 5; ++i) {
        cout << arr[i];
    }
}
