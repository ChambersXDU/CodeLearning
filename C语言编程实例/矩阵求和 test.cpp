#include <stdio.h>
 
int main() 
{
	int m, i, j, tmp;
	int sum_leading = 0, sum_counter = 0;
	int a[20][20], line[20] = {0}, column[20] = {0}, s[100];
	scanf("%d", &m);
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < m; j++) 
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++) //ÿ��Ԫ�����
	{
		for (j = 0; j < m; j++) 
		{
			line[i] += a[i][j];
		}
	}	
	for (j = 0; j < m; j++) //ÿ��Ԫ�����
	{
		for (i = 0; i < m; i++) 
		{
			column[j] += a[i][j];
		}
	} 
	for (i = 0; i < m; i++) //���Խ���Ԫ�����
	{
		sum_leading += a[i][i];
	} 
	for (i = 0, j = m - 1; i < m  ; i++, j--) //���Խ���Ԫ�����
	{
		sum_counter += a[i][j];
	} 
	for (i = 0; i < m; i++) //��ÿ��Ԫ�غ���������s
	{
		s[i] = line[i];
	} 
	for (j = 0; j < m; j++) //��ÿ��Ԫ�غ���������s
	{
		s[i] = column[j];
		i++;
	} 
	s[2 * m ] = sum_leading; //�������Խ���Ԫ�غ�
	s[2 * m + 1 ] = sum_counter; //���븱�Խ���Ԫ�غ�
	for (i = 0; i < 2 * m + 1; i++) 
	{
		for (j = 0; j < 2 * m + 1 - i; j++) 
		{
			if (s[j] < s[j + 1]) 
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < 2 * m + 2; i++) 
	{
		printf("%d ", s[i]);
	}
	return 0;
}
