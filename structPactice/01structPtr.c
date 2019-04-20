/**ָ��ṹ��ָ��*/

#include <stdio.h>

#define LEN 20

struct names {      //��1���ṹ
    char first[LEN];
    char last[LEN];
};

struct guy {        //��2���ṹ
    struct names handle;    //Ƕ�׽ṹ
    char favfood[LEN];
    char job[LEN];
    float incom;
};

int main(void)
{
    struct guy fellow[2] = {       //��ʼ��һ���ṹ����
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
    struct guy * him;       //����himΪָ��ṹ��ָ��
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);

    /**
    * fellow ��һ���ṹ���顣
    * fellow[0] ��һ���ṹ
    * himָ��fellow[0], him + 1ָ��fellow[1]
    * fellow[0].income == (*him).income == him->income   //����him == &barney
    **/

    him = &fellow[0];       //���߱�����ָ��ָ��δ�(�ṹ����fellow[0])

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
