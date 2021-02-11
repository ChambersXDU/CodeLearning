#include<stdio.h>
//#define max(a,b) 
//#define min(a,b) 
int main()
{
	int a,b,c=1,m,n;
	scanf("%d %d",&a,&b);
	m=(a>b)?(a):(b);
	n=(a<b)?(a):(b);

	if(n!=0)
	{
	  while(c!=0)
		{
			c=m%n;
			m=n;
			n=c;
			
		}
		printf("%d %d",m,a*b/m);
	
	}
	else printf("%d %d",m,a*b);
	return 0;
}
   
