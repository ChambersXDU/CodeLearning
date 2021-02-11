#include<stdio.h>
int main()
{
	int a[]={1,3,5};
	int *p=a;
	printf("%d %d",*p+1,*(p+1));
}


