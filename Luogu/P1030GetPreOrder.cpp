//
// Created by Chamb on 2021/12/24.
//
#include "iostream"
using namespace std;
void getPreOder(string mid,string post){
    if (!mid.empty()){
        int lastPosition = mid.length()-1;
        char root = *(post.end()-1);
        cout<<root;
        int rootPosition = mid.find(root);
        //中序ACGDBHZKX，后序CDGAHXKZB
        //ACGD B HZKX     CDGA HXKZ B
        string leftMid = mid.substr(0,rootPosition);//从0开始，取rootPositiion个长度
        string leftPost = post.substr(0,rootPosition);
        string rightMid = mid.substr(rootPosition+1);//从rootPosition+1开始，一直取到最后
        string rightPost = post.substr(rootPosition,lastPosition-rootPosition);
        getPreOder(leftMid,leftPost);//ACGD  CDGA
        getPreOder(rightMid,rightPost);//HZKX HXKZ
    }
}
int main(){
    string post,mid;
    cin>>mid>>post;
    getPreOder(mid,post);
}
