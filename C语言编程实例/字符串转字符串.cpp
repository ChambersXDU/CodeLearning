#include<stdio.h>
 
void convert(int n) {
	int i;
	if ((i = n / 10) != 0)
		convert(i);
	putchar(n % 10 + '0');
}
 
int main() {
	int num;
	scanf("%d", &num);
	if (num < 0) {
		printf("-");
		num = -num;
	}
	convert(num);
	printf("\n");
	return 0;
}
