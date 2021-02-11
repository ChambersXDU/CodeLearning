#include <stdio.h>
int main()
{
 int a,c;
 char b;
 scanf("%d%c%d",&a,&b,&c);
 if(b=='+')
    printf("%d%c%d=%d",a,b,c,a+c);
 if(b=='-')
       printf("%d%c%d=%d",a,b,c,a-c);
 if(b=='*')
    printf("%d%c%d=%d",a,b,c,a*c);
 if(b=='/')
    printf("%d%c%d=%d",a,b,c,a/c);
 if(b=='%')
    printf("%d%c%d=%d",a,b,c,a%c);
 return 0;
}
