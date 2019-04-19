#include <stdio.h>

#define SIZE 10

int sump(int ar[], int n);

int main(void)
{
    int marbles[SIZE] = {20, 30, 10, 5, 4, 18, 49, 29, 32, 68};
    long answer;

    answer = sump(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %u bytes.\n", sizeof marbles);

    return 0;
}

int sump(int ar[], int n)
{
    int i;
    int total = 0;

    for(i = 0; i < n; i++)
    {
        total += ar[i];
    }
    printf("The size of ar is %u bytes.\n", sizeof ar);

    return total;
}
