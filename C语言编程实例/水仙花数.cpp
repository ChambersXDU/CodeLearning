#include<stdio.h>

int function(int a,int b)
{
	int p,q;
	p=a<b?a:b;
	q=a>b?a:b;
	int n,count=0;
	for(n=p;n<q;n++)
	{
		int orin=n;
		int temp,Trisum=0;
		while(orin!=0)
		{
			temp=orin%10;
			Trisum+=temp*temp*temp;	
			orin=orin/10;
		}
		if(Trisum==n) count++;
	}
	return count; 
} 
int main()
{
	int p,a,b;
	scanf("%d %d",&a,&b);
	p=function(a,b);
	printf("%d",p);
}
