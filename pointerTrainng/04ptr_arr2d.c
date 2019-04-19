/**
* 指针与二维数
* 通过指针获取zippo的信息
**/

#include <stdio.h>

int main(void)
{
    /**
    *   可以用数组表示法，或指针表示法来表示一个数组元素
    *   zippo[m][n] == *(*(zippo + m) + n)
    *   pz[m][n] == *(*(pz + m) + n)
    **/

    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

    printf("   zippo = %p\n", zippo);
    printf("zippo[0] = %p\n\n", zippo[0]);

    printf("   zippo[2] = %p\n", zippo[2]);                 //zippo[2] <--> *(zippo + 2)   zippo[2]的地址
    printf("*(zipp + 2) = %p\n\n", *(zippo + 2));

    printf("   zippo[2] + 1 = %p\n", zippo[2] +1);          //zippo[2] +1 --zippo[2][1]的地址
    printf("*(zippo + 2) +1 = %p\n\n", *(zippo + 2) + 1);   //*(zippo + 2) + 1 --zippo[2][1]的地址

    printf("*(zippo[2] + 1) = %d\n", *(zippo[2] + 1));
    printf("*(*(zippo + 2) + 1) = %d\n\n", *(*(zippo + 2) + 1));


    printf("------------------------------------------\n\n");

    //zippo为数组首元素地址，该元素是一个内含两个int类型值的一位数组。因此pz必须指向一个内含两个int类型值的数组，而不是指向一个int类型值。
    int (*pz)[2];       //pz指向一个内含两个int类型值的数组；把pz声明为指向一个数组的指针，该数组内含两个int类型值。
    pz = zippo;

    printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);

    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);

    printf("    **pz = %d\n", **pz);

    printf(        "pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz + 2) + 1) = %d\n", *(*(pz + 2) + 1));

    return 0;
}

/*
   zippo = 0060FEEC
zippo[0] = 0060FEEC

   zippo[2] = 0060FEFC
*(zipp + 2) = 0060FEFC

   zippo[2] + 1 = 0060FF00
*(zippo + 2) +1 = 0060FF00

*(zippo[2] + 1) = 3
*(*(zippo + 2) + 1) = 3

------------------------------------------

   pz = 0060FEEC,    pz + 1 = 0060FEF4
pz[0] = 0060FEEC, pz[0] + 1 = 0060FEF0
  *pz = 0060FEEC,   *pz + 1 = 0060FEF0
pz[0][0] = 2
  *pz[0] = 2
    **pz = 2
pz[2][1] = 3
*(*(pz + 2) + 1) = 3

Process returned 0 (0x0)   execution time : 0.037 s
Press any key to continue.

*/



