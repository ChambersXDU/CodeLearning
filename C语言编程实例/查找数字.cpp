#include<stdio.h>
int main()
{
	int flag=0,n,k,a[100]={0},i=0;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]==k) {printf("%d ",i); flag=1;}
	}
	
	if(flag==0) printf("-1");
} 
