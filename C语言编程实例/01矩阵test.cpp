#include<stdio.h>
int main()
{
	int m,n,a[100][100],start,end;
	int i=0,j=0;
	scanf("%d %d",&m,&n);
	
	for(int i=0;i<m;i++) 
	{
		for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	}
	

	
	/*for(i=0;i<m;i++)
	{	
		int len=0,max=0;
		for(j=0;j<n;)
		{
			if(a[i][j]==0&&j+1<n)
			{
				len++;
			}
			else
			{
				if(len>max) 
				{
					max=len;
					end=j-1;
					start=j-len;
				}
				//j++;	
			}
			j++;
		}
		if(len) printf("%d %d\n",start,end);
		else printf("-1 -1\n");
	}*/
	
	for(i=0;i<m;i++)
	{
		int len=0,max=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1) len++;
			
			if(a[i][j+1]==0||j+1==n) 
			{
				if(len>max)
				{
					max=len;
					end=j;
					start=j-max+1;
					len=0;
				}
			}
		}
		if(max) printf("%d %d\n",start,end);
		else printf("-1 -1\n");
	}
	
}


