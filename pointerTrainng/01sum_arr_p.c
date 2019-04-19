#include <stdio.h>

#define SIZE 10

int sump(int * start, int * end);

int main(void)
{
    int marbles[SIZE] = {20, 30, 10, 5, 4, 18, 49, 29, 32, 68};
    long answer;

    answer = sump(marbles, marbles + SIZE);     //marbles + SIZE ָ������ĩβ����һ��λ��
    printf("The total number of marbles is %ld.\n", answer);

    return 0;
}

int sump(int * start, int * end)
{
    int total = 0;

    while (start < end)     //ѭ��������Ԫ����end��ָ��λ�õ�ǰһ��Ԫ�أ�endָ������ĩβ����һ��λ��
    {
        total += *start;    //������Ԫ�ص�ֵ������
        start++;            //��ָ��ָ����һ��Ԫ��
        /*
        һԪ�����*��++�����ȼ���ͬ������ɴ������󣬿�дΪ
        total += *start++;  //�ȼ��� total += *(start++); //������
        */
    }

    return total;
}
