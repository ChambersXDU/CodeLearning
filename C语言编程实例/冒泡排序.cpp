#include<stdio.h>
int main()
{
	int n,a[100000],t,i,j,flag=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]<a[j+1])	
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
				flag=1;
			}
		}	 
		if(flag==0) break;
	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
}


