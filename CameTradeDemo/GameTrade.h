#ifndef GAMETRADE_H_INCLUDED
#define GAMETRADE_H_INCLUDED

/*��Ʒ�ṹ googd/ptop(����) */
typedef struct _prop{
    int id;     //���ߵ�Ψһ���
    char name[50];  //��������
    double price;   //���ߵ���
    int stock;      //�����������ڱ�����,��ʾ�˵��ߵĵ�������
    char desc[200]; //���ߵĹ�������
}Prop;

/*�����ṹ */
typedef struct _bag{
    int playerId;   //������ұ��
    int count;      //��ǰ�����У����ߵ�����
    int max;        //��ǰ�����Ĳ������,�������û���rmb����
    Prop props[8];     //��ǰ�����еĵ�������
}Bag;

/*��ҽṹ */
typedef struct _player{
    int id;  //��ұ��
    char names[50];   //�û���/�ǳ�
    char pass[50];  //����
    Bag bag;    //��ҵı���
    double gold;    //��ҽ��--���Ի���ʾ�����Խ�100000ͭ��ת�������ҡ������ʾ
    double sysee;   //Ԫ������
}Player;

Prop * props;
Player * players;

static int propsCount = 0;
static int playerCount = 0;

void Init();
void ShowPops();
void ShowPlayers();
/*
* ���׺���
* ����1�����뽻�׵����ָ��-Ϊ�˷����޸���ҽ��׺�Ľ����
* ����2����ҹ������Ʒid
*/
void Trade(Player *player, int propId);

#endif // GAMETRADE_H_INCLUDED
