#include<stdio.h>
int main()
{
	int a, b;
	float A, B;
	scanf("%d %d", &a, &b);
	A=a*a*a*3.1415926/6000*7.86;

	B=b*b*b*3.1415926/6000*19.3;
 
	printf("%.3f %.3f", A, B);
	return 0;
}
