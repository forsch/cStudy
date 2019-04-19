/**
* ָ�����ά��
* ͨ��ָ���ȡzippo����Ϣ
**/

#include <stdio.h>

int main(void)
{
    /**
    *   �����������ʾ������ָ���ʾ������ʾһ������Ԫ��
    *   zippo[m][n] == *(*(zippo + m) + n)
    *   pz[m][n] == *(*(pz + m) + n)
    **/

    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

    printf("   zippo = %p\n", zippo);
    printf("zippo[0] = %p\n\n", zippo[0]);

    printf("   zippo[2] = %p\n", zippo[2]);                 //zippo[2] <--> *(zippo + 2)   zippo[2]�ĵ�ַ
    printf("*(zipp + 2) = %p\n\n", *(zippo + 2));

    printf("   zippo[2] + 1 = %p\n", zippo[2] +1);          //zippo[2] +1 --zippo[2][1]�ĵ�ַ
    printf("*(zippo + 2) +1 = %p\n\n", *(zippo + 2) + 1);   //*(zippo + 2) + 1 --zippo[2][1]�ĵ�ַ

    printf("*(zippo[2] + 1) = %d\n", *(zippo[2] + 1));
    printf("*(*(zippo + 2) + 1) = %d\n\n", *(*(zippo + 2) + 1));


    printf("------------------------------------------\n\n");

    //zippoΪ������Ԫ�ص�ַ����Ԫ����һ���ں�����int����ֵ��һλ���顣���pz����ָ��һ���ں�����int����ֵ�����飬������ָ��һ��int����ֵ��
    int (*pz)[2];       //pzָ��һ���ں�����int����ֵ�����飻��pz����Ϊָ��һ�������ָ�룬�������ں�����int����ֵ��
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



