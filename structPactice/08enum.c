/**使用枚举类型的值**/

#include <stdio.h>
#include <string.h>     //支持strcmp()/strchr()函数原型
#include <stdbool.h>

char * s_gets(char * st, int n);

enum spectrum { red, orange, yellow, green, blue, violet };
const char * colors [] = { "red", "orange", "yellow", "green", "blue", "violet" };  //指针数组

#define LEN 30

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Enter a color (empty line to quite):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)  //遍历枚举值
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
        {
            switch (color)
            {
            case red:
                puts("Roses are red.");
                break;
            case orange:
                puts("Poppies are orange.");
                break;
            case yellow:
                puts("Sunflowers are yellow.");
                break;
            case green:
                puts("Grass are green.");
                break;
            case blue:
                puts("Bluebells are blue.");
                break;
            case violet:
                puts("Violets are violet.");
                break;
            }
        }
        else
        {
            printf("I don't known about the color %s.\n", choice);
        }
        color_is_found = false;
        puts("Net color, please (empty line to quite):");
    }
    puts("Goodbye");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   //查找换行符
        if (find)                   //如果地址不是NULL
            *find = '\0';           //在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;           //处理输入行的剩余字符
    }
   // printf("ret_val is :%s\n", ret_val);
    return ret_val;
}

/*
Enter a color (empty line to quite):
blue
Bluebells are blue.
Net color, please (empty line to quite):
red
Roses are red.
Net color, please (empty line to quite):
yellow
Sunflowers are yellow.
Net color, please (empty line to quite):
purple
I don't known about the color purple.
Net color, please (empty line to quite):
pink
I don't known about the color pink.
Net color, please (empty line to quite):
green
Grass are green.
Net color, please (empty line to quite):

*/
