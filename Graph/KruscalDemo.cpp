////
//// Created by Chamb on 2021/12/19.
////
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
    int u,v,cost;
};
edge es[10000];
int n,m;
int x,y,z;
int root[1000];
int rank[1000];

//定义排序函数
bool comp(const edge &e1,const edge &e2){
    return e1.cost<e2.cost;
}
//并查集部分
//初始化n个元素
void init(int n){
    for(int i=0;i<n;i++){
        root[i]=i;
        rank[i]=0;
    }
}

//查询树的根
int find(int x){
    if(root[x]==x){
        return x;
    } else{
        return root[x]=find(root[x]);
    }
}

//合并x和y所属的集合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if(rank[x]<rank[y]){
        root[x]=y;
    }
    else{
        root[y]=x;
        if(rank[x]==rank[y])
        {
            rank[x]++;
        }
    }
}
//并查集部分结束

bool same(int x,int y){
    return find(x)==find(y);
}

int  a[1000][3];
int sum=0;
void kruskal(){
    sort(es,es+m,comp);
    init(n);
    int res=0;
    for(int i=0;i<m;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            a[sum][0]=min(e.u,e.v);
            a[sum][1]=max(e.u,e.v);
            a[sum][2]=e.cost;
            sum++;
        }
    }
}
int temp;
void change(int a0,int a1){
    temp=a0;
    a0=a1;
    a1=temp;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        es[i].u=x;
        es[i].v=y;
        es[i].cost=z;

    }
    kruskal();

    //冒泡排序
    for(int i=1;i<sum;i++){
        for(int j=i+1;j<sum;j++){
            if(a[i][0]>a[j][0]){
                change(a[i][0],a[j][0]);
                change(a[i][1],a[j][1]);
                change(a[i][2],a[j][2]);
            }

        }
    }
    for(int i=1;i<sum;i++){
        for(int j=i+1;j<sum;j++){
            if(a[i][0]==a[j][0])
            {
                if(a[i][1]>a[j][1]){
                    change(a[i][0],a[j][0]);
                    change(a[i][1],a[j][1]);
                    change(a[i][2],a[j][2]);
                }
            }
        }
    }
    for(int i=0;i<sum;i++){
        cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
    }
    return 0;
}

