#include <stdio.h>
#include <stdlib.h>
#include "account.h"

int main()
{
    Account account = {"��������", "�ܿ�ѷ", 30000, 28000};
    //double result = GetRepayment(account);
    double result = GetRepayment(&account);
    printf("Ӧ���%.2lf\n", result);
    printf("Ĭ������Ϊ��%s\n", account.bankName);
    return 0;
}
