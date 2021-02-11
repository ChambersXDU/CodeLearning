#include<stdio.h>
int main()
{
	int a,b,x;
	scanf("%d %d",&a,&b); 
	x=a%b;
	if(x==0) printf("yes");
	else printf("%d %d",a/b,a%b);
	return 0;
 } 
