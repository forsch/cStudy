#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime
{
    int year;   int month;  int day;
}MyTime;

/*
typedef struct _hero
{
    //char name[50]; //英雄名称
    char * name;    //指针方式，英雄名称
    char sex;      //英雄性格
    char job[20];  //英雄职业
    int life;      //英雄生命值
    double speed;  //攻击速度
    char abillity[20]; //英雄的特殊能力
    MyTime pubTime;    //英雄的上线时间
}Hero;
*/

//使用动态录入
//打印结果
//计算平均年龄
typedef struct _hero
{
    //char name[50]; //英雄名称
    char * name;     //英雄名称
    char sex;      //英雄性格
    char * job;  //英雄职业
    int life;      //英雄生命值
    double speed;  //攻击速度
    char * abillity; //英雄的特殊能力
    MyTime pubTime;    //英雄的上线时间
}Hero;

void Input();   //动态录入

void Show();    //显示英雄的详细信息


/*
结构数组：元素为结构类型的数组
结构数组的定义


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
    {"郭芙蓉", 29, "老板娘", "排山倒海"},
    {"吕秀才", 32, "账房", "子曾经曰过"}
};
*/
#endif // HERO_H_INCLUDED





