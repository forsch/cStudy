/**把指向结构的指针(结构的地址)作为参数传递*/

#include <stdio.h>

#define FUNDLEN 50

struct funds {      //第1个结构
    char      bank[FUNDLEN];
    double    bankfund;
    char      save[FUNDLEN];
    double    savefund;
};

double sum(const struct funds *);   //参数是一个指针

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n", sum(&stan));

    return 0;
}

double sum(const struct funds * money)
{
    return(money->bankfund + money->savefund);
}


/*
Stan has a total of $12576.21.

Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.

*/
