#include<stdio.h>
double function(int n)
{
	if(n==1)
	return 1;
	else
	return 1/(1+function(n-1));
	
}
int main()
{
	double a;
	a=func(5);
	printf("%f",a);
}


