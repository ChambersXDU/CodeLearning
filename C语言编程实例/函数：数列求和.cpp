#include<stdio.h>
float funca(int n)
{
	if(n==1) return 2;
	else if(n==2) return 3;
	else return funca(n-1)+funca(n-2);
}
float funcb(int n)
{
	if(n==1) return 1;
	else if(n==2) return 2;
	else return funcb(n-1)+funcb(n-2);
}
float f(int n)
{
	int i;
	float sum=0,a[100];
	
	for(i=0;i<n;i++)
	{
		a[i]=funca(i+1)/funcb(i+1);
		sum+=a[i];
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	printf("%.2f",f(n));
}
