#include<stdio.h>
int main()
{
	int n,m,i,j,a[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++) scanf("%d",&a[i][j]);
	}

	for(m=0;m<n;m++)
	{
		if(m%2!=0)
		{	
			i=0;j=m;
			while(i!=m+1)
			{
			
				printf("%d ",a[i][j]);
				i++; 
				j--;
			}
				
		}
		else
		{	
			i=m;j=0;
			while(j!=m+1)
			{
			
				printf("%d ",a[i][j]);
				i--; 
				j++;
			}	
		}
	}
	for(m=n;m<2*n;m++)
	{
		if(m%2!=0)
		{	
			i=m-n+1; j=n-1;
			while(i!=n)
			{
			
				printf("%d ",a[i][j]);
				i++; 
				j--;
			}
				
		}
		else
		{	
			i=n-1;j=m-n+1;
			while(j!=n)
			{
			
				printf("%d ",a[i][j]);
				i--; 
				j++;
			}	
		}
	
	}
	
}


