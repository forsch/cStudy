/**
* �ṹ���з�����������Ӧ��
* �����������ɸ���һ���ṹ�������Ϊ��������
**/

#include <stdio.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book {       //�ṹģ�壬���Ϊbook
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
        readfirst = (struct book) {"tensorflow",        //���������������ṹ��
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
������������Ϊ��������;

����������һ���ṹ���ɰѷ�����������Ϊʵ�ʲ�������
struct rect {double x; double y};
double rect_area(struct rect r) {return r.x * r.y;}
...
double area;
area = rect_area((struct rect) {10.5, 20.0});

����������һ����ַ���ɴ��ݸ����������ĵ�ַ��
struct rect {double x; double y};
double rect_areap(struct rect *rp) {return rp->x * rp->y;}
...
double area;
area = rect_areap(&(struct rect) {10.5, 20.0});

���������������к������ⲿ�����о�̬�洢�ڣ��������������ڿ��У�������Զ��洢���ڡ�

**/

/*
Enter test score: 90
You assigned reading:
tensorflow by sunny: $89.33

Process returned 0 (0x0)   execution time : 2.462 s
Press any key to continue.

*/
