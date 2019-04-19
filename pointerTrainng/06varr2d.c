/**
* ʹ�ñ䳤����ĺ���
**/

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);
/**
* ar��һ���䳤����(VLA)
* ǰ��������(rows �� cols)��Ϊ��3���βζ�ά���� ar ������ά�ȡ���Ϊar������Ҫʹ�� rows �� cols,�β��б��б���������ar֮ǰ�����������β�
* ����ʡ��ԭ���еĲ����������ǣ�������*������ʡ�Ե�ά��
* int sum2d(int rows, int cols, int ar[*][*]);  //ʡ����ά�Ȳ�����
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

    int varr[rs][cs];       //�䳤���� (VLA)

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
        varr[i][j] = i * j + j;

    printf("3 x 5 array\n");
    printf("sum of all elements = %d\n\n", sum2d(ROWS, COLS, junk));    //����ͳC����

    printf("2 x 6 array\n");
    printf("sum of all elements = %d\n\n", sum2d(ROWS - 1, COLS + 2, morejunk));    //����ͳC����

    printf("3 x 10 array\n");
    printf("sum of all elements = %d\n\n", sum2d(rs, cs, varr));    //����䳤����

    return 0;
}

/**
* ���䳤�����βεĺ���
* �ñ�����������������
* �˺������Դ��������С�Ķ�άint����
* �Ա䳤������Ϊ�βεĺ����ȿ��Դ���ͳC���飬Ҳ���Դ���䳤����
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



