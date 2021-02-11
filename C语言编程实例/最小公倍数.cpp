#include<stdio.h>
int main()
{
	int t,a,b;
		int i=1;
	scanf("%d %d",&a,&b);
	while (t%a==0||t%b==0)
	{
		t=a*i;
		i++;
	printf("%d",t);
	}
	
}
