#include<stdio.h>
int main()

{
	int maxyear,i;
	scanf("%d",&maxyear);
	for(i=maxyear;i>1949;i=i-4)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		printf("%d ",i);
	}
	
} 
