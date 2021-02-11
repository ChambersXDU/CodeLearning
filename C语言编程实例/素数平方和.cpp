#include<stdio.h>
int main()
{
	int x,y,i,sum=0;
	scanf("%d %d",&x,&y);
	int a=x<y?x:y;
	int b=x>y?x:y;
	for(i=a;i<=b;i++)
	{
		int k;
		for(k=2;k<i+1;k++)
		{
			if(i%k==0) break;
		
		}
			if(k==i) sum=sum+i*i;
	}
	printf("%d",sum);
}

