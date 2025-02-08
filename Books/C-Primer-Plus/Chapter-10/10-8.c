#include <stdio.h> 
#define SIZE1 7
#define SIZE2 3
#define FROM 3 - 1
#define TO 5 - 1
void cp_arr(double *, double *, int, int);

int main(void)
{
    double array[SIZE1] = {1, 2, 3, 4, 5, 6, 7};
    double to_copy[SIZE2];
    double *ar = array;
    double *tc = to_copy;

    printf("=> Эта программа копирует числа в заданном диапозоне");
    printf(" из одного массива в другой.\n");
    cp_arr(ar, tc, FROM, TO);
    for (int c = 0; c < ((TO) - (FROM) + 1); c++)
    {
        printf("=> to_copy[%d] -> %lf\n", c, to_copy[c]);
    }
    return 0;
}

void cp_arr(double *ar, double *tc, int from, int to)
{
    for (int i = 0; i < (to - from) + 1; i++)
    {
        *(tc + i) = *(ar + from + i);
    }
    return;
}