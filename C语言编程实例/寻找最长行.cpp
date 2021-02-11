#include<stdio.h>
#include<string.h>
int main(){
  int m,n=0;char a[100],b[100];
  while(strcmp(gets(a),"***end***")!=0)
  {
      m=strlen(a);
	  if(m>n){n=m;strcpy(b,a);}
	  if(m=n);
  }
  printf("%d\n%s\n",n,b);
  return 0;
}

