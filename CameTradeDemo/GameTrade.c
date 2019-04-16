#include <stdio.h>
#include "GameTrade.h"
#include <string.h>

void Init()
{
    // ��ʼ������
    static Prop propArray[] = {
        {1, "˫�����鿨", 3000, 10, "˫��666"},
        {2, "���õĵ���", 5000, 8, "ֻ��Զ��"},
        {3, "���������", 8000, 10, "����ר��"},
        {4, "�޼���", 13000, 5, "��ǹ���룬ˮ����"},
        {5, "ֱ��һ��", 83000, 10, "�����Ժ�׼�����ٳ�"},
    };
    propsCount = sizeof(propArray) / sizeof(Prop);
    props = propArray;  //����ָ���ָ��

    static Player playerArray[] = {
        {1, "����ëë��", "123456", .gold=50000, .bag.max = 8},
        {2, "������", "123456", .gold=150000, .bag.max = 8},
        {3, "ԭʼ����", "123456", .gold=500000, .bag.max = 8},
        {4, "�Ǻ�", "123456", .gold=1150000, .bag.max = 8},
    };
    playerCount = sizeof(playerArray) / sizeof(Player);
    players = playerArray;

}

void ShowPops()
{
    int i;
    if(props == NULL) return;
    //printf("���\t����\t����\t���\t��Ʒ����\n");
    printf("%-5s %-14s %-7s %5s %20s \n", "���" ,"����", "����", "���", "��Ʒ����");

    for(i = 0; i < propsCount; i++)
    {
        printf("%-5d %-14s %-7.0lf %5d %20s \n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
    }

}

void ShowPlayers()
{
    int i,j;
    if(players == NULL) return;
    printf("���\t %-14s���\n", "����");

    for(i = 0; i < playerCount; i++)
    {
        printf("%d\t %-14s %0.1f\n", players[i].id, players[i].names, players[i].gold);
        //printf("��ҵı����������£�\n");
        for(j = 0; j < players[i].bag.count; j++)
        {
            printf("\t%s\t%d\t\n", players[i].bag.props[j].name, players[i].bag.props[j].stock);
        }
        printf("\n");
    }
}

/**
* ���׺���
* ����1�����뽻�׵����ָ��-Ϊ�˷����޸���ҽ��׺�Ľ����
* ����2����ҹ������Ʒid
**/
void Trade(Player *player, int propId)
{
    //��Ҫ�жϣ���Ʒ��棬�������������ұ����ռ乻����
    int i;
    Prop *tradeProp; //��Ҫ�������Ʒָ��
    for(i =0; i < propsCount; i++)
    {
        if(propId == props[i].id)
        {
            tradeProp = &props[i]; //tradeProp = props + i;
            break;
        }
    }
    if(tradeProp->stock <= 0)
    {
        printf("�����Ҷ�û�������ˣ��̵궼�������\n");
        return;
    }
    if(player->gold < tradeProp->price)
    {
        printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣡ��\n");
        return;
    }
    if(player->bag.count >= player->bag.max && player->bag.count != 0)
    {
        printf("��������������ʧ�ܣ�\n");
        return;
    }


    //���㽻��������ִ�н��ײ���
    // 1.��Ʒ��� -1
    tradeProp->stock--;
    // 2.��ҽ��-��Ʒ����
    player->gold -= tradeProp->price;
    // 3.��ұ�����������
    //�ж���ұ������Ƿ����и���Ʒ
    //���û�и���Ʒ������Ʒ��ӵ������м���
    //����и���Ʒ�������еĸ���Ʒ����+1
    for(i = 0; i < player->bag.count; i++)
    {
        //��Ҫ�������Ʒid�뱳���е�ĳ����Ʒid��ͬ
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    //���û�и���Ʒ������Ʒ��ӵ�������
    if(i == player->bag.count)
    {
        //�򱳰��д���һ����Ʒ
        int newIndex = player->bag.count;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        player->bag.count++;

    }
}
