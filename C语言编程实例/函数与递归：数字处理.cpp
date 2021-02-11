#include<stdio.h>
int f(int n)
{
	int a,i,sum=0;
	while(n!=0)
	{
		a=n%10;
		sum+=a;
		n=n/10;
	}
	if(sum/10==0) return sum;
	else return f(sum);
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",f(a));
}

