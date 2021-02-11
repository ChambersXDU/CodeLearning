#include<stdio.h> 
int main()
{
 int year,t;
 scanf("%d",&year);
 if(year<=2000||year>2100){
  printf("Invalid year!"); //非21世纪 
 }
 else {
  for(int i=2001;i<=year;i++){
   if(i%4==0&&i%100!=0||i%400==0){ //&&表示且，||表示或 
    printf("%d\n",i);
   }
  } 
 }
 if(year<2004&&year>2000){
  printf("None");//无闰年 
 }
 return 0;
}
