#include "account.h"

/*
double GetRepayment(Account account)
{
    account.bankName = "��������"
    return account.limit - account.billAmount;
}

*/

double GetRepayment(const Account *account)
{
    //����ָ��Ƚ�Σ��
    //account->bankName = "��������";
    return account->limit - account->billAmount;
}
