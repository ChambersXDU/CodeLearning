#include<stdio.h>
int main()
{
	int M,a,b,c;
	scanf("%d",&M);
	a=M/100;
	b=(M-100*a)/10;
	c=M-100*a-10*b;
	printf("%d",a+b+c);
	return 0;
 }
  
