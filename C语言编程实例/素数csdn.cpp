#include<stdio.h>
int main()
{
	int conut = 0;
	int i = 0;
	for(i=100; i<=200; i++)     //先找出来100到200的所有整数,都为i
	{
		int j = 0;
		for(j=2; j<i; j++)      //用i去对除了1和它本身以外的数求余
		{
			if(i%j == 0)
				break;
		}
		if(j==i)
		{
			conut++;
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("素数个数为：%d\n", conut);
	return 0;
}
