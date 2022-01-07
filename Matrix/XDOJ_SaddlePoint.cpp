//
// Created by Chamb on 2021/12/6.
//
#include "iostream"
using namespace std;
int main(){
    int m,n;
    cin>>m;//行
    cin>>n;//列
    //若矩阵中的某个元素是第i行中的最小值，同时又是第j列中的最大值，
    // 则称此元素为该矩阵中的一个马鞍点。编写程序求出矩阵中的所有马鞍点。
    int array[10][10];
    int colMax[10][10]={0};//列最大
    int rowMin[10][10]={0};//行最小
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>array[i][j];
        }
    }
    int minIndex;
    int minCol;
    //求出行最小矩阵
    for (int row = 0; row < m; ++row) {
        minIndex = array[row][0];
        minCol = 0;
        for (int col = 0; col < n; col++) {
            if (array[row][col]<minIndex){
                minIndex = array[row][col];
                minCol = col;
            }
        }
        rowMin[row][minCol] = 1;
    }
    //求列最小矩阵
    int maxIndex;
    int maxRow;
    for (int col = 0; col < n; ++col) {
        maxIndex = array[0][col];
        maxRow = 0;
        for (int row = 0; row < n; row++) {
            if (array[row][col]>maxIndex){
                maxIndex = array[row][col];
                maxRow = row;
            }
        }
        colMax[maxRow][col] = 1;
    }
    int hasPoint = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rowMin[i][j]&&colMax[i][j]){
                hasPoint = 1;
                cout<<i+1<<" "<<j+1<<" ";
                cout<<array[i][j]<<" ";
            }
        }
    }
    if (!hasPoint){
        cout<<"NO";
    }
}
