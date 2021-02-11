#include <stdio.h>
int main(){
    int nums[10];
    int i;
   
    //从控制台读取用户输入
    for(i=0; i<10; i++){
        scanf("%d", &nums[i]);  //注意取地址符 &，不要遗忘哦
    }
   
    //依次输出数组元素
    for(i=0; i<10; i++){
        printf("%d ", nums[i]);
    }
   
    return 0;
}
