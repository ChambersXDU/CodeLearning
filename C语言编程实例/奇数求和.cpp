#include<stdio.h>
int main()
{
	int x,n=0,f1=0,f2=1;
 scanf("%d",&x);
 while(x)
 {if(x%2)
  {f1+=x; n++;}
  else f2*=x;
  scanf("%d",&x);  
 }
 printf("%.1f ",(float)f1/n,);
 return 0;
}
