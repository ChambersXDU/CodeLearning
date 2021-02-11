#include<stdio.h>

int F(int n)
{
	if(n==0) return 7;
	else if(n==1) return 11;
	else return F(n-1)+F(n-2); 
}

int fib(int n)
{
	return F(n);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
}

