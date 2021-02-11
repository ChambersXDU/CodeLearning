#include<stdio.h>

void BubbleSort(int a[], int len)
{
	int i, j, temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		if (a[i] < a[i + 1])
		{
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}

int main()
{
	int m,i,k,t,a[20][20];
	int sum1=0,sum2=0,rowSum=0,colSum=0;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	for(k=0;k<m;k++)
	scanf("%d",&a[i][k]);
	int sum[100];
	for(i=0;i<m;i++)
	{
		for(k=0;k<m;k++)
		{
			if(i==k) sum1+=a[i][k];
			else if(i+k==m-1) sum2+=a[i][k];
		}
	}
		sum[0]=sum1;
		sum[1]=sum2;
	
		for(i=0;i<m;i++)
		{
			rowSum=0;
			for(k=0;k<m;k++)
			{
				rowSum+=a[i][k];
			}	
			sum[i+2]=rowSum;
		}
		for(i=0;i<m;i++)
		{
			colSum=0;
			for(k=0;k<m;k++)
			{
				colSum+=a[k][i];
			}	
			sum[m+2+i]=colSum;
		}
		
	BubbleSort(sum, 2*m+2);
/* 	int flag=0,j=0;	
	
	
	
	for(i=0;i<2*m+1;i++)
	{
		for(j=0;j<2*m+1-i;j++)
		{
			if(sum[i]<sum[i+1])
			{
				t=sum[i];
				sum[i]=sum[i+1];
				sum[i+1]=t;
				flag=1;	
			}
		}
		if(!flag) break; 
	}*/
	
	for(i=0;i<(2*m+2);i++)
	{	
		printf("%d ",sum[i]);
	}
	printf("\n") ;
	
}


