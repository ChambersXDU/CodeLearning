#include<stdio.h>
int fib(int n)
{
	if(n==1) return 1;
	else if(n==0) return 0; 
	else return fib(n-1)+fib(n-2); 
}
int isprime(int n)
{
	int i,flag=1;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0) 
		{
			flag=0;break;
		}		
	}
	if(flag) return 1;
	else return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(isprime(n)) printf("yes");
	else printf("%d",fib(n));
	//printf("%d",fib(n));
}


