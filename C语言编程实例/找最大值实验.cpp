#include<stdio.h>
int main()
{
	int a=3,b=6,c=1,d=9,x;
	x=a>b ? a : ( c>d ? c : d );
	printf("%d",x);
}
