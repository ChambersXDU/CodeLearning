#include <stdio.h>
int main()
{
 int a,g,s,b,q,w;
 scanf("%d",&a);
 w=(a/10000)%10;
 q=(a/1000)%10;
 b=(a/100)%10;
 s=(a/10)%10;
 g=a%10; 
 printf("%d %d %d %d %d",w,q,b,s,g);
 return 0;
}
