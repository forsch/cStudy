#include "Hero.h"
#include <stdio.h>
#include <stdlib.h>

Hero heros[100] = {
    {"影流之主劫", 'm', "刺客", 579, 0.644, "位移", {2012, 8, 15}},
    {"琴瑟仙女", 'F', "法师", 452, 0.644, "减速、治疗", {2010, 3, 1}},
    {"疾风剑豪", 'm', "战士", 517, 0.67, "护盾、位移", {2013, 12, 23}}
};

int count = 3; //当前的英雄总数
void Input()
{
    //首先录入内容
    //第一个录入完毕后，询问是否继续录入
    char answer = "y";
    do{
        if (count == 100)
        {
            printf("英雄的栏目已满，请到游戏商城购买！");
            break;
        }
        printf("当前录入第%d位英雄的信息：\n", count + 1);
        printf("英雄名称：");
        heros[count].name = (char*)malloc(50);
        scanf("%s", heros[count].name);
        printf("性别：");
        fflush(stdin);
        heros[count].sex = getchar();
        fflush(stdin);
        printf("职业：");
        heros[count].job = (char*)malloc(50);
        scanf("%s", heros[count].job);
        heros[count].life = 1000;
        heros[count].speed = 0.644;
        heros[count].abillity = "上天入地";
        heros[count].pubTime.year = 2019;
        heros[count].pubTime.month = 3;
        heros[count].pubTime.day = 1;
        count++;    //录入完毕后，英雄总数+1
        printf("是否继续录入英雄信息:(y/n)");
        answer = getch();   //用户按下键后就立即触发下面语句，不会再让用户敲回车。
    }while(answer == 'y' || answer == 'Y');
}

void Show()
{
//    如何指导结构数组的大小
//    int len = sizeof(heros) / sizeof(Hero);
//
//    数组元素使用指针时，动态赋值需要首先分配内存
//    printf("请输入名称:");
//    heros[0].name = (char *)malloc(50);
//    scanf("%s", heros[0].name);
//    printf("结构数组的元素个数 %d\n", len);

    int i ;
    printf("\n");
    for (i = 0; i < count; i++)
    {
        //数组方式
        //printf("%s\t%s\t%d-%d-%d\n", heros[i].name, heros[i].job, heros[i].pubTime.year, heros[i].pubTime.month, heros[i].pubTime.day);
        //指针方式
        printf("%s\t%s\t%d-%d-%d\n", (heros + i)->name, (heros + i)->job, (heros + i)->pubTime.year, (heros + i)->pubTime.month, (heros + i)->pubTime.day);
    }
}
