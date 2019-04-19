/**ָ�����**/
#include <stdio.h>

int main(void)
{
    int urn[5] = {100, 200, 300, 400, 500};
    int * ptr1, * ptr2, * ptr3;

    ptr1 = urn;         //������urn����Ԫ�ص�ַ����ָ��
    ptr2 = &urn[2];     //�������3��Ԫ�صĵ�ַ����ָ��

    printf("pointer value, dereferenced pointer, pointernaddress:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    /**ָ��ӷ�**/
    ptr3 = ptr1 + 4;
    printf("\nading an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));

    ptr1++;    //����ָ��
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",ptr1, *ptr1, &ptr1);

    ptr2--;    //�ݼ�ָ��
    printf("\nvalues after ptr2--:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",ptr2, *ptr2, &ptr2);

    --ptr1;     //�ָ���ʼֵ
    ++ptr2;
    printf("\npointer reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    /**һ��ָ���ȥ��һ��ָ��**/
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n", ptr2, ptr1, ptr2 - ptr1);

    /**һ��ָ���ȥһ������**/
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);

}

/*
���н����
pointer value, dereferenced pointer, pointernaddress:
ptr1 = 0060FEF8, *ptr1 = 100, &ptr1 = 0060FEF4

ading an int to a pointer:
ptr1 + 4 = 0060FF08, *(ptr1 + 4) = 500

values after ptr1++:
ptr1 = 0060FEFC, *ptr1 = 200, &ptr1 = 0060FEF4

values after ptr2--:
ptr2 = 0060FEFC, *ptr2 = 200, &ptr2 = 0060FEF0

pointer reset to original values:
ptr1 = 0060FEF8, ptr2 = 0060FF00

subtracting one pointer from another:
ptr2 = 0060FF00, ptr1 = 0060FEF8, ptr2 - ptr1 = 2

subtracting an int from a pointer:
ptr3 = 0060FF08, ptr3 - 2 = 0060FF00

Process returned 0 (0x0)   execution time : 0.041 s
Press any key to continue.

*/
