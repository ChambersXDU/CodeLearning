#include<stdio.h>
int main()
{
	int n,qq,sum=0,t,a,s;
	scanf("%d %d",&n,&qq);
	t=qq%10;
	while(qq!=0)
	{
		a=qq%10;
		sum=sum+a;
		qq=qq/10; 
	}
	s=sum%n ;
	if(t==n && s==0)
	printf("yes");
	else printf("no"); 
	
	
	
 } 
