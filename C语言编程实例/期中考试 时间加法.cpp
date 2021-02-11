#include<stdio.h>
int main()
{
	int m,n,h,t;
	scanf("%d %d",&m,&n);
	h=n%24;
	t=(m+n)%24;
	printf("%d",t);
 } 
