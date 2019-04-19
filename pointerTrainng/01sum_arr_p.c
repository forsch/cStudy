#include <stdio.h>

#define SIZE 10

int sump(int * start, int * end);

int main(void)
{
    int marbles[SIZE] = {20, 30, 10, 5, 4, 18, 49, 29, 32, 68};
    long answer;

    answer = sump(marbles, marbles + SIZE);     //marbles + SIZE 指向数组末尾的下一个位置
    printf("The total number of marbles is %ld.\n", answer);

    return 0;
}

int sump(int * start, int * end)
{
    int total = 0;

    while (start < end)     //循环最后处理的元素是end所指向位置的前一个元素，end指向数组末尾的下一个位置
    {
        total += *start;    //把数组元素的值加起来
        start++;            //让指针指向下一个元素
        /*
        一元运算符*和++的优先级相同，结合律从右往左，可写为
        total += *start++;  //等价于 total += *(start++); //更常用
        */
    }

    return total;
}
