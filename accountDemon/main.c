#include <stdio.h>
#include <stdlib.h>
#include "account.h"

int main()
{
    Account account = {"建设银行", "杰克逊", 30000, 28000};
    //double result = GetRepayment(account);
    double result = GetRepayment(&account);
    printf("应还款：%.2lf\n", result);
    printf("默认银行为：%s\n", account.bankName);
    return 0;
}
