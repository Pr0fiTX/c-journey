#include <stdio.h>
#define SIZE 5
void copy_arr(double target1[], double source[], int size);
void copy_pntr(double* target2, double* source, int size);
void copy_ptrs(double* target3, double* source, double* source_end);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_pntr(target2, source, SIZE);
    for (int a = 0; a < SIZE; a ++)
    {
        printf("=> target2[%d] -> %.1lf\n", a, target2[a]);
    }
    copy_ptrs(target3, source, source + 5);
    putchar('\n');
    for (int d = 0; d < SIZE; d++)
    {
        printf("=> target3[%d] -> %.1lf\n", d, target3[d]);
    }
    return 0;
}

void copy_ptrs(double *target3, double *source, double *source_end)
{
    while (source != source_end)
    {
        *target3++ = *source++;
    }
    return;
}

void copy_arr(double target1[], double source[], int size)
{
    for (int i = 0; i < size; i++)
    {
        target1[i] = source[i];
        printf("=> target1[%d] -> %.1lf\n", i, target1[i]);
    }
    putchar('\n');
    return;
}

void copy_pntr(double *target2, double *source, int size)
{
    int i = 0;

    while (size--)
    {
        *target2++ = *source++;
    }
    return;
}