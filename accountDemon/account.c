#include "account.h"

/*
double GetRepayment(Account account)
{
    account.bankName = "招商银行"
    return account.limit - account.billAmount;
}

*/

double GetRepayment(const Account *account)
{
    //传递指针比较危险
    //account->bankName = "招商银行";
    return account->limit - account->billAmount;
}
