/**
* 结构体中符合字面量的应用
* 复合字面量可赋给一个结构体或者作为函数参数
**/

#include <stdio.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book {       //结构模板，标记为book
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;

    printf("Enter test score: ");
    scanf("%d", &score);

    if (score >= 84)
    {
        readfirst = (struct book) {"tensorflow",        //复合字面量赋给结构体
                                    "sunny",
                                    89.33};
    }
    else
    {
        readfirst = (struct book) {"PyTorch",
                                    "forsch",
                                    76.56};
    }

    printf("You assigned reading:\n");
    printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);

    return 0;
}

/**
复合字面量作为函数参数;

若函数接受一个结构，可把符合字面量作为实际参数传递
struct rect {double x; double y};
double rect_area(struct rect r) {return r.x * r.y;}
...
double area;
area = rect_area((struct rect) {10.5, 20.0});

若函数接受一个地址，可传递复合字面量的地址：
struct rect {double x; double y};
double rect_areap(struct rect *rp) {return rp->x * rp->y;}
...
double area;
area = rect_areap(&(struct rect) {10.5, 20.0});

复合字面量在所有函数的外部，具有静态存储期；若符合字面量在块中，则具有自动存储周期。

**/

/*
Enter test score: 90
You assigned reading:
tensorflow by sunny: $89.33

Process returned 0 (0x0)   execution time : 2.462 s
Press any key to continue.

*/
