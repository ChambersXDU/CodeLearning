#include<stdio.h>
int main()
{
	int x; 
	scanf("%d",&x);
	int d;
	int ret=0;
	
	while (x>0)
		{
			d=x%10;
			ret=ret*10+d;
			x=x/10;
			
		}
	printf("%d",ret);
	
	return 0;
	
	
}
