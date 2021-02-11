#include<stdio.h>
int main()
{
	int i,a=1;
	
	for(i=2;i<=20;i++)
	{
		int j=0 ;
		for(j=2;j<=i-1;j++)
		{
			if(i%j==0)  break;
		}
		
		if(j==i) printf("%d ",i);
	}
 } 
