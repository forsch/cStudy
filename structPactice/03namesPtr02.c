/**���ݲ����ؽṹ**/

#include <stdio.h>
#include <string.h>

#define ELEN 30

struct namect {
    char      fname[ELEN];
    char      lname[ELEN];
    int       letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char * s_gets(char * st, int n);

int main(void)
{
    struct namect person;

    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

    return 0;
}

struct namect getinfo(void)
{
    struct namect temp;
    printf("Please enter your first name.\n");
    s_gets(temp.fname, ELEN);
    printf("Please enter your last name.\n");
    s_gets(temp.lname, ELEN);

    return temp;
}

struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);

    return info;
}

void showinfo(struct namect info)
{
    printf("%s %s, your name contains %d letters.\n", info.fname, info.lname, info.letters);
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
    return ret_val;
}

/*
Please enter your first name.
sunny
Please enter your last name.
forsch
sunny forsch, your name contains 11 letters.

Process returned 0 (0x0)   execution time : 8.617 s
Press any key to continue.

*/
