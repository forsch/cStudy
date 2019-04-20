/**使用指针和malloc()**/

#include <stdio.h>
#include <string.h>     //提供strcpy(), strlen()的原型
#include <stdlib.h>     //提供malloc(), free()的原型

#define SLEN 81

struct namect {
    char * fname;   //使用指针
    char * lname;
    int letters;
};

void getinfo(struct namect *);      //分配内存
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);      //调用函数时释放内存
char * s_gets(char * st, int n);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}

void getinfo(struct namect * pst)
{
    char temp[SLEN];

    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);

    //分配内存以储存名
    pst->fname = (char *) malloc(strlen(temp) + 1);
    //把名拷贝到动态分配的内存中
    strcpy(pst->fname, temp);

    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);

    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);

    /**
    *   这两个字符串都未存储在结构中，他们存储在malloc()分配的内存地址中，结构中存储着这两个字符串的地址
    *   处理字符串的函数通常使用字符串的地址
    **/
}

void makeinfo(struct namect * pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst)
{
    free(pst->fname);
    free(pst->lname);
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
Please enter your first name.
sunny
Please enter your last name.
forsch
sunny forsch, your name contains 11 letters.

Process returned 0 (0x0)   execution time : 6.424 s
Press any key to continue.
*/
