/**ʹ�ú���ָ��**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);     //��ȡ����ĩβ
void show(void (*fp)(char *), char * str);
void ToUpper(char *);   //���ַ���ת��Ϊ��д
void ToLower(char *);   //���ַ���ת��ΪСд
void Transpose(char *); //��Сдת��
void Dummy(char *);     //�������ַ���
//typedef void(*PFUNC)(char *);
int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void(*pfun)(char *);    //����һ������ָ�룬��ָ��ĺ�������char *���͵Ĳ������޷���ֵ
    //PFUNC pfun;

    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice)     //switch������ú���ָ��
            {
            case 'u':pfun = ToUpper;    break;
            case 'l':pfun = ToLower;    break;
            case 't':pfun = Transpose;  break;
            case 'o':pfun = Dummy;      break;
            }
            strcpy(copy, line);     //Ϊshow()��������һ��
            show(pfun, copy);       //�����û���ѡ��ʹ��ָ���ĺ���
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");

    return 0;
}


char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase    l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();        //��ȡ�û�������
    ans = tolower(ans);     //ת��ΪСд
    eatline();              //����������

    while (strchr("ulton", ans) == NULL)
    {
        puts("Please enter a u, l, o, or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char * str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char * str)
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char * str)
{
    //���ı��ַ���
}

void show(void(*fp)(char *), char * str)
{
    (*fp)(str);     //���û�ѡ���ĺ���������str
    puts(str);      //��ʾ���
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
Enter a string (empty line to quit):
i Love Sunny
Enter menu choice:
u) uppercase    l) lowercase
t) transposed case o) original case
n) next string
t
I lOVE sUNNY
Enter menu choice:
u) uppercase    l) lowercase
t) transposed case o) original case
n) next string
l
i love sunny
Enter menu choice:
u) uppercase    l) lowercase
t) transposed case o) original case
n) next string
u
I LOVE SUNNY
Enter menu choice:
u) uppercase    l) lowercase
t) transposed case o) original case
n) next string
o
i Love Sunny
Enter menu choice:
u) uppercase    l) lowercase
t) transposed case o) original case
n) next string
n
Enter a string (empty line to quit):

Bye!

Process returned 0 (0x0)   execution time : 104.009 s
Press any key to continue.

*/
