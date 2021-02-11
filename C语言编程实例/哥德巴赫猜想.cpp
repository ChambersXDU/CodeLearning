#include<stdio.h>
int main()
{
	int primer1,primer2,i,n,j,k,a=1;
	scanf("%d",&n);
	
	//for(i=2;i<n/2;i++)
//	{
		for(j=i;j<n/2;j++)
		{
			for(k=2;k<j/2;k++)
			{
				if(j%k==0) a=0; break;
			}
			if(a) primer1=k,primer2=n-k;
			
			
			for(k=2;k<j/2;k++)
			{
				if(primer2%k==0) a=0; break;
			}
			if(a) 	printf("%d %d",primer1,primer2);
			
		}
		
//	}
}
