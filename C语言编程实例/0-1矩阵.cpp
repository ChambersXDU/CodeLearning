#include<stdio.h>
int main()
{
	int m,n,a[100][100],start,end,j=0;
	scanf("%d %d",&m,&n);
	
	for(int i=0;i<m;i++) for(int j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	
	for(int i=0;i<m;i++)
	{
		int len=0,max=0;
		while(j<n)
		{
			while(a[i][j]!=0)
			{
				len++;
				j++;
			} 
			if(len>max) 
				{
					max=len;
					end=j;
					start=end-len+1;
				}

			j++;
			
		}	
		if(len) printf("%d %d\n",start,end);
		else printf("-1 -1\n");
	}	
	
}


