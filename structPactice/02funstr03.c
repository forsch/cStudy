/**传递一个结构**/

#include <stdio.h>

#define FUNDLEN 50

struct funds {      //第1个结构
    char      bank[FUNDLEN];
    double    bankfund;
    char      save[FUNDLEN];
    double    savefund;
};

double sum(struct funds moolah);   //参数是一个结构

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n", sum(stan));

    return 0;
}

double sum(const struct funds moolah)
{
    return(moolah.bankfund + moolah.savefund);
}


/*
Stan has a total of $12576.21.

Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.

*/
