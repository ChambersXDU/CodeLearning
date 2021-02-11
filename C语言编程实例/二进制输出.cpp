#include<stdio.h>
#include<math.h>
int main()
{
	int a,i=0,sum=0,b;
	scanf("%d",&a);
	while(a%10!=0)
	{
		
		b=a%10;
		sum+=b*pow(2,i);
		a/=10;
		i=i+1;
		}
	printf("%d",sum);
}

