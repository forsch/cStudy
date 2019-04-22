/**�ṹ���鴫�ݸ�����**/

#include <stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
    char    bank[FUNDLEN];
    double  bankfund;
    char    save[FUNDLEN];
    double  savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
    struct funds jones[N] = {
        {
            "Garlic-Melon Bank",
            4032.27,
            "Lucky's Saving and Loan",
            8543.94
        },
        {
            "Honest Jack's Bank",
            3620.88,
            "Party Time Saving",
            3802.91
        }
    };

    printf("The Jones have a total of $%.2f.\n", sum(jones, N));  //sum(jones, N) �ȼ��� sum(&jones[0], N)
    /**
        ������jones�Ǹ�������׵�ַ��������������Ԫ��(jones[0])�ĵ�ַ��
        ָ��money�ĳ�ʼֵ�൱��ͨ�� money = &jones[0];
        money ָ��jones�������Ԫ�أ�money[0]�Ǹ��������һ�����ơ�
        money[1]�ǵ�2��Ԫ�أ�ÿ��Ԫ�ض���һ��funds���͵Ľṹ�����Զ�����ʹ��.���������funds���ͽṹ�ĳ�Ա��
    **/

    return 0;

}

double sum(const struct funds money[], int n)   //���ܸı�ԭʼ���ݣ�ʹ��const�޶���
{
    double total;
    int i;

    for (i = 0, total = 0; i < n; i++)
    {
        total += money[i].bankfund + money[i].savefund;
    }
    return total;
}

/**
    1.���԰���������Ϊ�����е�1���ṹ��ĵ�ַ���ݸ�������
    2.�����������ʾ���������� �е������ṹ
        sum(&jones[0], N)��sum(jones, N) Ч����ͬ---jones��&jones[0]��ֵ��ͬ����������ṹ��ַ��Ҳ�������׵�ַ
**/
