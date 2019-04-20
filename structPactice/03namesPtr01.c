/**使用指向结构的指针**/

#include <stdio.h>
#include <string.h>

#define ELEN 30

struct namect {
    char      fname[ELEN];
    char      lname[ELEN];
    int       letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char * s_gets(char * st, int n);

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect * pst)
{
    printf("Please enter your first name.\n");
    s_gets(pst->fname, ELEN);
    printf("Please enter your last name.\n");
    s_gets(pst->lname, ELEN);
}

void makeinfo(struct namect * pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
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
    return ret_val;
}

/*
Please enter your first name.
sunny
Please enter your last name.
forsch
sunny forsch, your name contains 11 letters.

Process returned 0 (0x0)   execution time : 7.001 s
Press any key to continue.

*/
