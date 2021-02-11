#include<stdio.h>
int main()
{
	int scanNum,i,j,t,trans,num2=0;
	scanf("%d",&scanNum);
	int a[100];
	for (i=0;i<scanNum;i++) scanf("%d",&a[i]);
	for(j=0;j<scanNum-1;j++)
	{
		for (i=0;i<scanNum-j-1;i++)
	    {
    		trans=0;
    		if (a[i]<=a[i+1]) //switch
    		{
    			trans=a[i+1];
    			a[i+1]=a[i];
    			a[i]=trans;
    		}
    	}
	}
	for (i=0;i<scanNum;i++)	if (a[i]%2==0) printf("%d ",a[i]);
	for (i=0;i<scanNum;i++) if (a[i]%2!=0) printf("%d ",a[i]);
	printf("\n");
	return 0;
}

