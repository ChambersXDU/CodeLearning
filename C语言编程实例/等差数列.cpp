#include<stdio.h>
int main()
{
	int  i,j,n,a[100],flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	int mark=0;
	for(int i=0;i<n-1;i++)
	{
	
		for(int j=0;j<n-i-1;j++)
		{
			int temp=0;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				mark=1;
			}
		}
		if(mark==0) break;
	}
	
	for(j=0;j<n-2;j++)
	{
		if(2*a[j+1]!=a[j]+a[j+2]) flag=0;	
	} 
	
	if(flag==1) printf("%d",a[1]-a[0]);
	else printf("no");
}


