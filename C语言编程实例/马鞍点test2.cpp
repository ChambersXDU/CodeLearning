#include<stdio.h>
int isMin(int *p,int i,int m)
{
	int min=*p,t,ans1=0;
	for(t=0;t<m;t++)
	{
    	if(*(p-i+t)<min)
		{
			return 0;
			ans1=1;
		}
    }
    if(ans1==0)
	{
    	return 1;
	} 
}
int isMax(int *p,int i,int n)
{
	int max=*p,f,ans=0;
	for(f=0;f<n;f++)
	{
		if(*(p-100*i+100*f)>max)
		{
			return 0;
			ans=1;
		}
	}
	if(ans==0)
	{
    	return 1;
    }
}
int main()
{
	int a[100][100],(*p)[100]=a;
	int m,n;
	int i,j;
	int ans=0;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++) for(j=0;j<n;j++)  scanf("%d",&a[i][j]);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(isMin(*(p+100*i+j),j,n)==1&&isMax(*(p+100*i+j),i,m)==1)
	    	{
	    		ans=1;
	    		printf("%d %d %d\n",i,j,*(p+100*i+j));
	    	}
		}
	}
	if(ans==0) printf("no\n");
} 

