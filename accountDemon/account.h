#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _account
{
    char * bankName;
    char * username;
    double limit;   //账户的额度
    double billAmount;  //当月账单金额
}Account;

//得到某个账户当月应还款数
//传递结构变量时,是复制整个结构变量的值到函数中，效率低
//double GetRepayment(Account account);

//参数传递的是结构指针- 递名片
//参数中增加const后，会让指针更加安全
double GetRepayment(const Account *account);

#endif // ACCOUNT_H_INCLUDED

/*
note:传递结构成员

//信用卡账户
struct Account
{
    char * bankName;    //银行名称
    char * userName;    //用户名称
    double limit;       //账户额度
    double billAmount;  //当月账单
};


//-------------------
struct Account zsAcc;
zsAcc.bankName = "招商银行"；
zsAcc.userName = "forsch"；
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(zsAcc.limit, zsAcc.billAmount);
//-------------------


//计算并返回当月应还款
//传递结构成员
double GetRepayment(double m1, double m2)
{
    return m1 - m2;
}

//计算并返回当月应还款
//传递结构本身---此方法更优
double GetRepayment(struct Account account)
{
    return account.limit - account.billAmount;
}

//-------------------
struct Account zsAcc;
zsAcc.bankName = "招商银行"；
zsAcc.userName = "forsch"；
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(zsAcc);
printf("本月应还款: %.2lf\n", result);
//-------------------


结构体最大的好处：
封装参数


//----
传递结构指针

//信用卡账户
struct Account
{
    char * bankName;    //银行名称
    char * userName;    //用户名称
    double limit;       //账户额度
    double billAmount;  //当月账单
};

//计算并返回当月应还款
double GetRepayment(const struct Account *account) //结构指针
{
    return account->limit - account->billAmount;
}

struct Account zsAcc;
zsAcc.bankName = "招商银行"；
zsAcc.userName = "forsch"；
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(&zsAcc);
printf("本月应还款: %.2lf\n", result);

----------------------------------------------
结构作为函数参数的3种方式
1.传递结构成员
2.传递结构
    优点：函数处理的是原始数据的副本，保护了原始数据
    缺点：老版本C不支持；传递结构浪费时间和空间
    一般用来处理小型结构数据

3.传递结构的地址
    优点：程序的执行速度快，效率高
    缺点：无法保护数据，函数中的操作有可能会意外影响原结构中的数据(可加const限制)
    为追求效率，建议用此方案

------------------------------------------------
使用typedef简化定义代码
typedef:
    可以为某一类型自定义名称

    typedef unsigend char Byte；
    Byte btValue1；

    typedef struct[hero]
    {
        char * name;
        int age;
        char * job;
        char * skill;
    }Hero;

    //使用：
    Hero hero = {"forsch", 23, "探索者", "飞上蓝天"};

typedef并没有创造任何新类型，只是某个已存在的类型增加一个方便使用的标签

*/
