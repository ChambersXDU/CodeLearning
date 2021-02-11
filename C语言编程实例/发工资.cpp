#include <stdio.h>
 
int main()
{
	int money;
	int m100 = 0;
	int m50  = 0;
	int m20  = 0;
	int m10  = 0;
	int m5   = 0;
	int m1   = 0;
 
	scanf ("%d", &money);
	
	m100  = money / 100; 
	money = money % 100; 
	
	m50   = money / 50; 
	money = money % 50; 
	
	m20   = money / 20; 
	money = money % 20;  
	
	m10   = money / 10;  
	money = money % 10;  
 
	m5    = money / 5;   
	money = money % 5;
	
	m1    = money / 1; 
	
	
	printf("%d %d %d %d %d %d",m100,m50,m20,m10,m5,m1);
	
	return 0;
}
//其实主要原理就是，先发大额钞票，不能发了再换小面额，一直到只能用1元面额为止。 

