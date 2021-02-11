#include<stdio.h>
int ismin(int *p,int i,int m);
int ismax(int *p,int j,int n);
int main()
{
	int m,n,i,j,flag=0;
	int a[100][100];
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);
	int (*p)[100]=a;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{	if(ismin((*(p+i)+j),j,n)&&ismax((*(p+i)+j),i,m))
			//if(ismin(*(p+100*i+j),j,n)&&ismax(*(p+100*i+j),i,m))
			{
			 //printf("%d %d %d",i,j,a[i][j]); 
			 flag=1;
			 break;
			}
		}		
	}
	
	if(flag==0) printf("no");
	else printf("%d %d %d",i,j,a[i][j]);
	return 0; 
} 

int ismin(int *p,int j,int n)
{
	int flag=1;
	int min=*p;
	int t;
	for(t=0;t<n;t++)
	{
		if(*(p-j+t)<min) 	flag=0;		    
	}	
	return flag;
}

int ismax(int *p,int i,int m)
{
	int flag=1;
	int max=*p;
	int t;
	for(t=0;t<m;t++)
	{
		if(*(p-100*i+t)>max)	flag=0;	
		//if(*(p-100*i+100*t)>max)	flag=0;		    
	}	
	return flag;
}
