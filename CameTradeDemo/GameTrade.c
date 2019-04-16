#include <stdio.h>
#include "GameTrade.h"
#include <string.h>

void Init()
{
    // 初始化数据
    static Prop propArray[] = {
        {1, "双倍经验卡", 3000, 10, "双机666"},
        {2, "腐烂的道袍", 5000, 8, "只可远观"},
        {3, "生锈的铁剑", 8000, 10, "新手专用"},
        {4, "无极炮", 13000, 5, "刀枪不入，水火不侵"},
        {5, "直升一级", 83000, 10, "吃了以后保准还想再吃"},
    };
    propsCount = sizeof(propArray) / sizeof(Prop);
    props = propArray;  //设置指针的指向

    static Player playerArray[] = {
        {1, "超级毛毛虫", "123456", .gold=50000, .bag.max = 8},
        {2, "奥特曼", "123456", .gold=150000, .bag.max = 8},
        {3, "原始天尊", "123456", .gold=500000, .bag.max = 8},
        {4, "星河", "123456", .gold=1150000, .bag.max = 8},
    };
    playerCount = sizeof(playerArray) / sizeof(Player);
    players = playerArray;

}

void ShowPops()
{
    int i;
    if(props == NULL) return;
    //printf("编号\t名称\t单价\t库存\t商品介绍\n");
    printf("%-5s %-14s %-7s %5s %20s \n", "编号" ,"名称", "单价", "库存", "商品描述");

    for(i = 0; i < propsCount; i++)
    {
        printf("%-5d %-14s %-7.0lf %5d %20s \n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
    }

}

void ShowPlayers()
{
    int i,j;
    if(players == NULL) return;
    printf("编号\t %-14s金币\n", "名称");

    for(i = 0; i < playerCount; i++)
    {
        printf("%d\t %-14s %0.1f\n", players[i].id, players[i].names, players[i].gold);
        //printf("玩家的背包数据如下：\n");
        for(j = 0; j < players[i].bag.count; j++)
        {
            printf("\t%s\t%d\t\n", players[i].bag.props[j].name, players[i].bag.props[j].stock);
        }
        printf("\n");
    }
}

/**
* 交易函数
* 参数1：参与交易的玩家指针-为了方便修改玩家交易后的金币数
* 参数2：玩家购买的商品id
**/
void Trade(Player *player, int propId)
{
    //需要判断：商品库存，玩家余额够不够，玩家背包空间够不够
    int i;
    Prop *tradeProp; //需要购买的商品指针
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
        printf("地主家都没有余粮了，商店都被买空啦\n");
        return;
    }
    if(player->gold < tradeProp->price)
    {
        printf("钱包都是瘪的，这里可是看钱的社会！！\n");
        return;
    }
    if(player->bag.count >= player->bag.max && player->bag.count != 0)
    {
        printf("背包已满，交易失败！\n");
        return;
    }


    //满足交易条件，执行交易操作
    // 1.商品库存 -1
    tradeProp->stock--;
    // 2.玩家金币-商品单价
    player->gold -= tradeProp->price;
    // 3.玩家背包道具增加
    //判断玩家背包中是否已有该商品
    //如果没有该商品，该商品添加到背包中即可
    //如果有该商品，背包中的该商品总数+1
    for(i = 0; i < player->bag.count; i++)
    {
        //若要购买的商品id与背包中的某个商品id相同
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    //如果没有该商品，将商品添加到背包中
    if(i == player->bag.count)
    {
        //向背包中创建一个商品
        int newIndex = player->bag.count;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        player->bag.count++;

    }
}
