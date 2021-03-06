#include <stdio.h>
#include <stdlib.h>
#include "GameTrade.h"

/*
模拟实现道具店购物功能
    商店暂时只支持一种类型的商品
    商品具备名称、价格、库存等属性
    模拟玩家购买游戏道具:
    1.玩家选择要购买的道具
    2.玩家同意交易后扣除相应游戏币
    3.对应商品库存 -1
    4.玩家背包中增加商品或该商品数量 +1



显示所有道具
玩家选择要购买的道具
1
检测玩家的金钱-道具价格
道具的库存-1
玩家背包中的道具+1


结构：
1.商品结构-名称、单位、库存量、描述
2.玩家结构-编号、名称、密码、金钱、[背包]
3.背包结构-玩家编号、游戏道具、商品[10]、道具数量、最大道具数量

*/

int main()
{
    //1.初始化数据
    Init();
    printf("\n**********交易前****************************************\n");
    ShowPops();
    ShowPlayers();

    Trade(&players[0], 3);
    Trade(&players[0], 2);
    Trade(&players[0], 1);
    Trade(&players[1], 4);
    Trade(&players[2], 1);
    Trade(&players[3], 5);

    printf("\n\n************交易后************************************\n");
    ShowPops();
    ShowPlayers();
    return 0;
}
