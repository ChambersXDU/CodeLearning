#include<stdio.h>
#include<string.h>

void count(char a[100],int num[5]);
int main()
{
	int i;
	char string[100];
	gets(string);
	int len=strlen(string),num[5]={0};
	int *p1=&num[0],*p2=&num[1],*p3=&num[2],*p4=&num[3],*p5=&num[4];
	count(string,num);
	for(i=0;i<5;i++)
	{
		num[i];
		printf("%d ",num[i]);
	}
}

 void count(char a[100],int num[5])
{
	int i=0;
	//int *p1=num[0],*p2=num[2],*p3=num[3],*p4=num[4],*p5=num[5];
	int *p1=&num[0],*p2=&num[1],*p3=&num[2],*p4=&num[3],*p5=&num[4];
	while(a[i]!='\0') 
		{			
		if(a[i]>=65&&a[i]<=90) *p1+=1;
		else if(a[i]>=97&&a[i]<=122) *p2+=1;
		else if(a[i]==' ') *p3+=1;
		else if(a[i]>=48&&a[i]<=57) *p4+=1;
		else  *p5+=1;
		i++;
		}
	
}
