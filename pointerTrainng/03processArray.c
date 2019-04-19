/**处理数组**/
#include <stdio.h>
#define SIZE 5

void show_array(const double ar[], int n);  //使用const
void mult_array(double ar[], int n, double mult);

int main(void)
{
    double dip[SIZE] = {20.7, 17.66, 8.2, 15.3, 22.22};

    printf("The origin dip array:\n");
    show_array(dip , SIZE);

    mult_array(dip, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE);

    return 0;
}

/**显示数组的内容**/
void show_array(const double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%8.3f", ar[i]);
    }
    printf("\n");
}

/**把数组每个元素都乘以相同的值**/
void mult_array(double ar[], int n, double mult)
{
    int i;

    for (i = 0; i < n; i++)
        ar[i] *= mult;
}

/*
The origin dip array:
  20.700  17.660   8.200  15.300  22.220
The dip array after calling mult_array():
  51.750  44.150  20.500  38.250  55.550

Process returned 0 (0x0)   execution time : 0.021 s
Press any key to continue.

*/
