#include<stdio.h>

void func(int n)
{
	int i=0,k,sum=0,a[100],t;
	int flag=1;
	while(n!=0)
	{
		t=n%10;
		a[i]=t;
		sum+=t;
		n=n/10;
		i++;
	}
	for(k=0;k<i/2;k++)
	{
		if(a[k]!=a[i-k-1])
		{
			flag=0;break;
		}
	}
	if(flag) printf("%d",sum);
	else printf("no");
}

int main()
{
	int n;
	scanf("%d",&n);
	func(n); 
}


