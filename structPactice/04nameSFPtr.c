/**ʹ��ָ���malloc()**/

#include <stdio.h>
#include <string.h>     //�ṩstrcpy(), strlen()��ԭ��
#include <stdlib.h>     //�ṩmalloc(), free()��ԭ��

#define SLEN 81

struct namect {
    char * fname;   //ʹ��ָ��
    char * lname;
    int letters;
};

void getinfo(struct namect *);      //�����ڴ�
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);      //���ú���ʱ�ͷ��ڴ�
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

    //�����ڴ��Դ�����
    pst->fname = (char *) malloc(strlen(temp) + 1);
    //������������̬������ڴ���
    strcpy(pst->fname, temp);

    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);

    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);

    /**
    *   �������ַ�����δ�洢�ڽṹ�У����Ǵ洢��malloc()������ڴ��ַ�У��ṹ�д洢���������ַ����ĵ�ַ
    *   �����ַ����ĺ���ͨ��ʹ���ַ����ĵ�ַ
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
        find = strchr(st, '\n');   //���һ��з�
        if (find)                   //�����ַ����NULL
            *find = '\0';           //�ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue;           //���������е�ʣ���ַ�
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
