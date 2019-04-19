/**
* 使用变长数组的函数
**/

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);
/**
* ar是一个变长数组(VLA)
* 前两个参数(rows 和 cols)作为第3个形参二维数组 ar 的两个维度。因为ar的声明要使用 rows 和 cols,形参列表中必须在声明ar之前声明这两个形参
* 可以省略原型中的参数名，但是，必须用*来代替省略的维度
* int sum2d(int rows, int cols, int ar[*][*]);  //省略了维度参数名
**/

int main(void)
{
    int i, j;
    int rs = 3;
    int cs = 10;

    int junk[ROWS][COLS] = {
            {2, 4, 6, 8},
            {3, 5, 7, 9},
            {12, 10, 8, 6},
    };

    int morejunk[ROWS - 1][COLS + 2] = {
            {20, 30, 40, 50, 60, 70},
            {5, 6, 7, 8, 9, 10}
    };

    int varr[rs][cs];       //变长数组 (VLA)

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
        varr[i][j] = i * j + j;

    printf("3 x 5 array\n");
    printf("sum of all elements = %d\n\n", sum2d(ROWS, COLS, junk));    //处理传统C数组

    printf("2 x 6 array\n");
    printf("sum of all elements = %d\n\n", sum2d(ROWS - 1, COLS + 2, morejunk));    //处理传统C数组

    printf("3 x 10 array\n");
    printf("sum of all elements = %d\n\n", sum2d(rs, cs, varr));    //处理变长数组

    return 0;
}

/**
* 带变长数组形参的函数
* 用变量代替行数和列数
* 此函数可以处理任意大小的二维int数组
* 以变长数组作为形参的函数既可以处理传统C数组，也可以处理变长数组
**/
int sum2d(int rows, int cols, int ar[rows][cols])
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            tot += ar[r][c];

    return tot;
}


/*
3 x 5 array
sum of all elements = 80

2 x 6 array
sum of all elements = 315

3 x 10 array
sum of all elements = 270


Process returned 0 (0x0)   execution time : 0.024 s
Press any key to continue.

*/



