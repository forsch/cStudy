#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _account
{
    char * bankName;
    char * username;
    double limit;   //�˻��Ķ��
    double billAmount;  //�����˵����
}Account;

//�õ�ĳ���˻�����Ӧ������
//���ݽṹ����ʱ,�Ǹ��������ṹ������ֵ�������У�Ч�ʵ�
//double GetRepayment(Account account);

//�������ݵ��ǽṹָ��- ����Ƭ
//����������const�󣬻���ָ����Ӱ�ȫ
double GetRepayment(const Account *account);

#endif // ACCOUNT_H_INCLUDED

/*
note:���ݽṹ��Ա

//���ÿ��˻�
struct Account
{
    char * bankName;    //��������
    char * userName;    //�û�����
    double limit;       //�˻����
    double billAmount;  //�����˵�
};


//-------------------
struct Account zsAcc;
zsAcc.bankName = "��������"��
zsAcc.userName = "forsch"��
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(zsAcc.limit, zsAcc.billAmount);
//-------------------


//���㲢���ص���Ӧ����
//���ݽṹ��Ա
double GetRepayment(double m1, double m2)
{
    return m1 - m2;
}

//���㲢���ص���Ӧ����
//���ݽṹ����---�˷�������
double GetRepayment(struct Account account)
{
    return account.limit - account.billAmount;
}

//-------------------
struct Account zsAcc;
zsAcc.bankName = "��������"��
zsAcc.userName = "forsch"��
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(zsAcc);
printf("����Ӧ����: %.2lf\n", result);
//-------------------


�ṹ�����ĺô���
��װ����


//----
���ݽṹָ��

//���ÿ��˻�
struct Account
{
    char * bankName;    //��������
    char * userName;    //�û�����
    double limit;       //�˻����
    double billAmount;  //�����˵�
};

//���㲢���ص���Ӧ����
double GetRepayment(const struct Account *account) //�ṹָ��
{
    return account->limit - account->billAmount;
}

struct Account zsAcc;
zsAcc.bankName = "��������"��
zsAcc.userName = "forsch"��
zsAcc.limit = 50000;
zs.Acc.billAmount = 35000;

double result = GetRepayment(&zsAcc);
printf("����Ӧ����: %.2lf\n", result);

----------------------------------------------
�ṹ��Ϊ����������3�ַ�ʽ
1.���ݽṹ��Ա
2.���ݽṹ
    �ŵ㣺�����������ԭʼ���ݵĸ�����������ԭʼ����
    ȱ�㣺�ϰ汾C��֧�֣����ݽṹ�˷�ʱ��Ϳռ�
    һ����������С�ͽṹ����

3.���ݽṹ�ĵ�ַ
    �ŵ㣺�����ִ���ٶȿ죬Ч�ʸ�
    ȱ�㣺�޷��������ݣ������еĲ����п��ܻ�����Ӱ��ԭ�ṹ�е�����(�ɼ�const����)
    Ϊ׷��Ч�ʣ������ô˷���

------------------------------------------------
ʹ��typedef�򻯶������
typedef:
    ����Ϊĳһ�����Զ�������

    typedef unsigend char Byte��
    Byte btValue1��

    typedef struct[hero]
    {
        char * name;
        int age;
        char * job;
        char * skill;
    }Hero;

    //ʹ�ã�
    Hero hero = {"forsch", 23, "̽����", "��������"};

typedef��û�д����κ������ͣ�ֻ��ĳ���Ѵ��ڵ���������һ������ʹ�õı�ǩ

*/
