#include "Hero.h"
#include <stdio.h>
#include <stdlib.h>

Hero heros[100] = {
    {"Ӱ��֮����", 'm', "�̿�", 579, 0.644, "λ��", {2012, 8, 15}},
    {"��ɪ��Ů", 'F', "��ʦ", 452, 0.644, "���١�����", {2010, 3, 1}},
    {"���罣��", 'm', "սʿ", 517, 0.67, "���ܡ�λ��", {2013, 12, 23}}
};

int count = 3; //��ǰ��Ӣ������
void Input()
{
    //����¼������
    //��һ��¼����Ϻ�ѯ���Ƿ����¼��
    char answer = "y";
    do{
        if (count == 100)
        {
            printf("Ӣ�۵���Ŀ�������뵽��Ϸ�̳ǹ���");
            break;
        }
        printf("��ǰ¼���%dλӢ�۵���Ϣ��\n", count + 1);
        printf("Ӣ�����ƣ�");
        heros[count].name = (char*)malloc(50);
        scanf("%s", heros[count].name);
        printf("�Ա�");
        fflush(stdin);
        heros[count].sex = getchar();
        fflush(stdin);
        printf("ְҵ��");
        heros[count].job = (char*)malloc(50);
        scanf("%s", heros[count].job);
        heros[count].life = 1000;
        heros[count].speed = 0.644;
        heros[count].abillity = "�������";
        heros[count].pubTime.year = 2019;
        heros[count].pubTime.month = 3;
        heros[count].pubTime.day = 1;
        count++;    //¼����Ϻ�Ӣ������+1
        printf("�Ƿ����¼��Ӣ����Ϣ:(y/n)");
        answer = getch();   //�û����¼������������������䣬���������û��ûس���
    }while(answer == 'y' || answer == 'Y');
}

void Show()
{
//    ���ָ���ṹ����Ĵ�С
//    int len = sizeof(heros) / sizeof(Hero);
//
//    ����Ԫ��ʹ��ָ��ʱ����̬��ֵ��Ҫ���ȷ����ڴ�
//    printf("����������:");
//    heros[0].name = (char *)malloc(50);
//    scanf("%s", heros[0].name);
//    printf("�ṹ�����Ԫ�ظ��� %d\n", len);

    int i ;
    printf("\n");
    for (i = 0; i < count; i++)
    {
        //���鷽ʽ
        //printf("%s\t%s\t%d-%d-%d\n", heros[i].name, heros[i].job, heros[i].pubTime.year, heros[i].pubTime.month, heros[i].pubTime.day);
        //ָ�뷽ʽ
        printf("%s\t%s\t%d-%d-%d\n", (heros + i)->name, (heros + i)->job, (heros + i)->pubTime.year, (heros + i)->pubTime.month, (heros + i)->pubTime.day);
    }
}
