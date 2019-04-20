/**把结构成员作为参数传递*/

#include <stdio.h>

#define FUNDLEN 50

struct funds {      //第1个结构
    char      bank[FUNDLEN];
    double    bankfund;
    char      save[FUNDLEN];
    double    savefund;
};

double sum(double, double);

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));  //结构成员作为函数参数

    return 0;
}

double sum(double x, double y)
{
    return(x + y);
}


/*
Stan has a total of $12576.21.

Process returned 0 (0x0)   execution time : 0.024 s
Press any key to continue.

*/
