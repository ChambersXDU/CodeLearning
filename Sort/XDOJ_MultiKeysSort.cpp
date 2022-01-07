//
// Created by Chamb on 2021/12/27.
//
#include "iostream"
#include "algorithm"
using namespace std;

struct student{
    int age;
    string name;
    int grade;
};

bool cmp(student s1,student s2){
    if (s1.grade == s2.grade){
        if (s1.name == s2.name){
            return s1.age<s2.age;
        }
        return s1.name<s2.name;
    }
    return s1.grade>s2.grade;
}

int main(){
    int n;
    cin>>n;
    student s[100];
    for (int i = 0; i < n; ++i) {
        cin>>s[i].name>>s[i].age>>s[i].grade;
    }
    sort(s,s+n,cmp);
    for (int i = 0; i < n; ++i) {
        cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].grade<<endl;
    }
}
