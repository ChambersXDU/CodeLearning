#include<math.h>
#include<stdio.h> 
int main()
{
	int n;
	scanf("%d",&n);
	int a[2000];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int min = 10000;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
	{
		{
			int curr = abs(a[i] - a[j]);
			if(curr<min)
				min = curr;
		} 
	}
	printf("%d",min);
	return 0;
}
