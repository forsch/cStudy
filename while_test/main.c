//������2+4+6+...+n ֮�ʹ��� 1000ʱ��n����Сֵ�Լ� 2+4+6+...n ֮�͡�

#include <stdio.h>

/*
int main(void)
{
    int i = 1;
	int sum = 0;

	while (sum <= 1000)
	{
		if ((i%2) == 0)
		{
			sum = sum + i;
		}
		i++;
	}

	printf("wthile the sum of 2+4+6+...+n more than 1000,the min n is:%d\n", i-1);
	printf("wthile the sum of 2+4+6+...+n more than 1000,the sum is:%d\n", sum);

}
*/

int main(void)
{
    int i = 1;
	int sum = 0;

	do
	{
		if ((i%2) == 0)
		{
			sum = sum + i;
		}
		i++;
	}while (sum <= 1000);

	printf("wthile the sum of 2+4+6+...+n more than 1000,the min n is:%d\n", i-1);
	printf("wthile the sum of 2+4+6+...+n more than 1000,the sum is:%d\n", sum);

}

