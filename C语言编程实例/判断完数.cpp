#include<stdio.h>
int main()
{
	int n,i,sum;

	
for(n=1;n<2000;n++) 
	
	{
		sum=0; //位置非常重要！ 
		for(i=1;i<=n/2;i++)
		{	
		
			if(n%i==0) sum=sum+i;
		 } 
	 if(sum==n) printf("%d ",n);
	}
 } 
