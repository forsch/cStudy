#ifndef GAMETRADE_H_INCLUDED
#define GAMETRADE_H_INCLUDED

/*商品结构 googd/ptop(道具) */
typedef struct _prop{
    int id;     //道具的唯一编号
    char name[50];  //道具名称
    double price;   //道具单价
    int stock;      //库存量；如果在背包中,表示此道具的叠加数量
    char desc[200]; //道具的功能描述
}Prop;

/*背包结构 */
typedef struct _bag{
    int playerId;   //所属玩家编号
    int count;      //当前背包中，道具的数量
    int max;        //当前背包的插槽总数,可以让用户用rmb购买
    Prop props[8];     //当前背包中的道具数组
}Bag;

/*玩家结构 */
typedef struct _player{
    int id;  //玩家编号
    char names[50];   //用户名/昵称
    char pass[50];  //密码
    Bag bag;    //玩家的背包
    double gold;    //玩家金币--人性化显示，可以将100000铜币转换成银币、金币显示
    double sysee;   //元宝数量
}Player;

Prop * props;
Player * players;

static int propsCount = 0;
static int playerCount = 0;

void Init();
void ShowPops();
void ShowPlayers();
/*
* 交易函数
* 参数1：参与交易的玩家指针-为了方便修改玩家交易后的金币数
* 参数2：玩家购买的商品id
*/
void Trade(Player *player, int propId);

#endif // GAMETRADE_H_INCLUDED
