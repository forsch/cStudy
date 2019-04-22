/**结构数组传递给函数**/

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

    printf("The Jones have a total of $%.2f.\n", sum(jones, N));  //sum(jones, N) 等价于 sum(&jones[0], N)
    /**
        数组名jones是该数组的首地址，即，该数组首元素(jones[0])的地址。
        指针money的初始值相当于通过 money = &jones[0];
        money 指向jones数组的首元素，money[0]是该数组的另一个名称。
        money[1]是第2个元素，每个元素都是一个funds类型的结构，所以都可以使用.运算符访问funds类型结构的成员。
    **/

    return 0;

}

double sum(const struct funds money[], int n)   //不能改变原始数据，使用const限定符
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
    1.可以把数组名作为数组中第1个结构体的地址传递给函数。
    2.可以用数组表示法访问数组 中的其它结构
        sum(&jones[0], N)与sum(jones, N) 效果相同---jones和&jones[0]的值相同，都是数组结构地址，也是数组首地址
**/
