/**指向结构的指针*/

#include <stdio.h>

#define LEN 20

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
    struct guy fellow[2] = {       //初始化一个结构数组
        {
            { "Ewen", "Villard" },
            "grilled salmon",
            "personality coach",
            100000.00
        },
        {
            { "Rodney", "Swillbelly" },
            "tripe",
            "tabloid editor",
            500000.00
        }
    };
    struct guy * him;       //定义him为指向结构的指针
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);

    /**
    * fellow 是一个结构数组。
    * fellow[0] 是一个结构
    * him指向fellow[0], him + 1指向fellow[1]
    * fellow[0].income == (*him).income == him->income   //假设him == &barney
    **/

    him = &fellow[0];       //告诉编译器指针指向何处(结构变量fellow[0])

    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f \t (*him).income is $%.2f \t fellow[1].incom is $%.2f\n", him->incom, (*him).incom, fellow[1].incom);

    him++;

    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);

    return 0;
}

/*
address #1: 0060FE54 #2: 0060FEA8
pointer #1: 0060FE54 #2: 0060FEA8
him->income is $100000.00        (*him).income is $100000.00     fellow[1].incom is $500000.00
him->favfood is tripe: him->handle.last is Swillbelly

Process returned 0 (0x0)   execution time : 0.023 s
Press any key to continue.

*/
