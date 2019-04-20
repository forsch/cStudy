/**嵌套结构体*/

#include <stdio.h>

#define LEN 20

const char  * msgs[5] = {       //指针数组   ？？为什么要用指针数组
    "  Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special  kind of guy. we must get together",
    "over a delicious ",
    " and have a few laughs"
};

struct names {      //第1个结构
    char first[LEN];
    char last[LEN];
};

struct guy {        //第2个结构
    struct names handle;    //嵌套结构
    char favfood[LEN];
    char job[LEN];
    float incom;
};

int main(void)
{
    struct guy fellow = {       //初始化一个结构变量
        { "Ewen", "Villard" },
        "grilled salmon",
        "personality coach",
        100000.00
    };

    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s\n", msgs[0], fellow.handle.last);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s\n", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.incom > 15000.00)
        puts("!!");
    else
        puts("!");

    return 0;
}

/*
Dear Ewen,

  Thank you for the wonderful evening, Villard
You certainly prove that a personality coach
is a special  kind of guy. we must get together
over a delicious grilled salmon and have a few laughs
!!

Process returned 0 (0x0)   execution time : 0.039 s
Press any key to continue.

*/
