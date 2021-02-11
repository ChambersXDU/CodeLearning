#include<stdio.h>
int main()
{
	int i,n,a[1000];
	int para=1;
	scanf("%d",&n);
	
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(i=0;i<n-1;i++)
	{
		
		if(a[i]!=a[i+1])
	    para=para+1 ;
	}
	printf("%d",para);
 } 
