/**Ƕ�׽ṹ��*/

#include <stdio.h>

#define LEN 20

const char  * msgs[5] = {       //ָ������   ����ΪʲôҪ��ָ������
    "  Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special  kind of guy. we must get together",
    "over a delicious ",
    " and have a few laughs"
};

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
    struct guy fellow = {       //��ʼ��һ���ṹ����
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
