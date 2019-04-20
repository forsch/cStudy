/**�����������Աʹ��**/

#include <stdio.h>
#include <stdlib.h>

struct flex
{
    int count;
    double average;
    double scores[];   //�����������Ա
};

void showFlex(const struct flex * p);

int main(void)
{
    struct flex * pf1, * pf2;
    int n = 5;
    int i;
    int tot = 0;

    //Ϊ�ṹ���������洢�ռ�
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));     //n-->scoresԪ�ظ���
    pf1->count = n;
    for (i = 0; i < n; i++)
    {
        pf1->scores[i] = 20.1 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);

    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for (i = 0; i < n; i++)
    {
        pf2->scores[i] = 20.0 - i / 2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot / n;
    showFlex(pf2);
    free(pf1);
    free(pf2);

    return 0;
}

void showFlex(const struct flex * p)
{
    int i;
    printf("Scores : ");
    for (i = 0; i < p->count; i++)
    {
        printf("%g\t", p->scores[i]);
    }
    printf("\nAverage: %g\n", p->average);
}

/*
Scores : 20.1   19.1    18.1    17.1    16.1
Average: 18
Scores : 20     19.5    19      18.5    18      17.5    17      16.5    16
Average: 17

Process returned 0 (0x0)   execution time : 0.042 s
Press any key to continue.

*/
