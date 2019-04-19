/**
* 处理二维数组的函数
**/

#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int rows);
int sum2d(int(*ar)[COLS], int rows);    //等价于 int sum2d(int ar[][COLS], int rows);
/**
* int sum2d(int ar[][4], int rows);   --有效的声明
* int sum2d(int ar[][], int rows);   --无效的声明
*
* 编译器会把数组表示法转换成指针表示法，eg：ar[1]转换成ar + 1,编译器对ar + 1求值 要知道ar所指向对象的大小
* int sum2d(int ar[][4], int rows); 声明，表示 ar 指向内含4个int类型值的数组，所以ar + 1是该地址加上16个字节;
* 若第二个括号为空，编译器就不知道如何处理了
**/


int main(void)
{
    int junk[ROWS][COLS] = {
            {2, 4, 6, 8},
            {3, 5, 7, 9},
            {12, 10, 8, 6},
    };

    sum_rows(junk , ROWS);
    sum_cols(junk, ROWS);
    printf("sum of all elements = %d\n", sum2d(junk, ROWS));

    return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
    int r, c, tot;

    for (r =0; r < rows; r++)
    {
        tot = 0;
        for (c = 0; c < COLS; c++)
        {
            tot += ar[r][c];
        }
        printf("row %d: sum = %d\n", r, tot);
    }
}

void sum_cols(int ar[][COLS], int rows)
{
    int r, c, tot;

    for (c = 0; c < COLS; c++)
    {
        tot = 0;
        for (r =0; r < rows; r++)
        {
            tot += ar[r][c];
        }
        printf("col %d: sum = %d\n", c, tot);
    }
}

int sum2d(int ar[][COLS], int rows)
{
    int r, c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
        tot += ar[r][c];

    return tot;
}

/*
row 0: sum = 20
row 1: sum = 24
row 2: sum = 36
col 0: sum = 17
col 1: sum = 19
col 2: sum = 21
col 3: sum = 23
sum of all elements = 80

Process returned 0 (0x0)   execution time : 0.040 s
Press any key to continue.

*/



