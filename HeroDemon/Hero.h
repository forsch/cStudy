#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime
{
    int year;   int month;  int day;
}MyTime;

/*
typedef struct _hero
{
    //char name[50]; //Ӣ������
    char * name;    //ָ�뷽ʽ��Ӣ������
    char sex;      //Ӣ���Ը�
    char job[20];  //Ӣ��ְҵ
    int life;      //Ӣ������ֵ
    double speed;  //�����ٶ�
    char abillity[20]; //Ӣ�۵���������
    MyTime pubTime;    //Ӣ�۵�����ʱ��
}Hero;
*/

//ʹ�ö�̬¼��
//��ӡ���
//����ƽ������
typedef struct _hero
{
    //char name[50]; //Ӣ������
    char * name;     //Ӣ������
    char sex;      //Ӣ���Ը�
    char * job;  //Ӣ��ְҵ
    int life;      //Ӣ������ֵ
    double speed;  //�����ٶ�
    char * abillity; //Ӣ�۵���������
    MyTime pubTime;    //Ӣ�۵�����ʱ��
}Hero;

void Input();   //��̬¼��

void Show();    //��ʾӢ�۵���ϸ��Ϣ


/*
�ṹ���飺Ԫ��Ϊ�ṹ���͵�����
�ṹ����Ķ���


struct Role
{
    char * name;
    int age;
    char * job;
    char * skill;
}roles[25];

struct Role roles[25];

//----------------------------

struct Role
{
    char * name;
    int age;
    char * job;
    char * skill;
}roles[] = {
    {"��ܽ��", 29, "�ϰ���", "��ɽ����"},
    {"�����", 32, "�˷�", "������Ի��"}
};
*/
#endif // HERO_H_INCLUDED





